## Why to use `st + (en - st)/2` formula instead of `(st + en)/2`?

Note (why use `mid = st + (en - st)/2`):
 - `(st + en)/2` can overflow 32-bit int when st and en are large.
 - In real code, st and en are array indices (0..n-1), so they rarely approach `INT_MAX`.
 - Still, use the safer form as best practice.

Important nuance:
 - If st itself were `INT_MAX`, even `st + 1` would overflow.
   In practice, indices won’t be that large because arrays aren’t that big.
   This note is about avoiding earlier overflow from adding two large numbers.

Demonstration (with large but plausible indices):
```
   st = 2,000,000,000, en = 2,000,000,010
   (st + en) = 4,000,000,010  → overflows 32-bit int before dividing by 2
   st + (en - st)/2 = 2,000,000,000 + (10/2) = 2,000,000,005  → safe
```
 Reference limits:
   `INT_MIN = -2147483648`, `INT_MAX = 2147483647` (32-bit signed int)
