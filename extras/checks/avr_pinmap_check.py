#!/usr/bin/env python3
"""Check FastTouch.h's AVR pin maps for internal consistency.

Within each map, __digitalPinToPortReg, __digitalPinToDDRReg and
__digitalPinToPINReg must test the same pin ranges in the same order and name
the same port letter for each range (PORTx / DDRx / PINx). The 644 map before
80f236a failed this: its DDR and PIN macros tested pins 8-15 twice, sending
pins 16-23 to port A.

usage: avr_pinmap_check.py [path/to/FastTouch.h]
       (default: src/FastTouch.h of the repository this script is in)
exit 0 when every map is consistent, 1 when one is not, and an error when
no map is found, which would mean the parser, not the header, is broken.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, "..", "..", "src", "FastTouch.h")
lines = open(path, encoding="utf-8").read().split("\n")

defs = []   # (line number, macro kind, body)
i = 0
while i < len(lines):
    m = re.match(r"#define __digitalPinTo(Port|DDR|PIN)Reg\(P\)(.*)", lines[i])
    if m:
        start, body = i + 1, m.group(2)
        while body.rstrip().endswith("\\"):
            body = body.rstrip()[:-1]
            i += 1
            body += " " + lines[i]
        defs.append((start, m.group(1), body))
    i += 1


def normal(body, kind):
    prefix = {"Port": "PORT", "DDR": "DDR", "PIN": "PIN"}[kind]
    body = re.sub(r"&%s([A-L])\b" % prefix, r"&REG_\1", body)
    return re.sub(r"\s+", "", body)


bad = 0
maps = 0
for k in range(0, len(defs) - 2):
    a, b, c = defs[k], defs[k + 1], defs[k + 2]
    if (a[1], b[1], c[1]) != ("Port", "DDR", "PIN"):
        continue
    maps += 1
    na, nb, nc = normal(a[2], "Port"), normal(b[2], "DDR"), normal(c[2], "PIN")
    ok = na == nb == nc
    bad += not ok
    print(f"{'ok      ' if ok else 'MISMATCH'} map at line {a[0]}: Port/DDR/PIN macros "
          f"{'agree' if ok else 'differ'}")
    if not ok:
        for kind, n in (("DDR", nb), ("PIN", nc)):
            if n != na:
                j = next((x for x in range(min(len(n), len(na))) if n[x] != na[x]), min(len(n), len(na)))
                print(f"         {kind} departs from Port at: ...{n[max(0, j - 30):j + 30]}...")
print(f"{maps} maps checked, {bad} inconsistent")
if maps == 0:
    sys.exit("no maps found: the parser, not the header, is broken")
sys.exit(1 if bad else 0)
