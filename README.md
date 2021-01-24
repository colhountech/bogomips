# bogomips

This app calculated time to do 100 millions operations of nothing.
Useful for comparing PCs and Raspberry Pis

# version

v0.0.1 - Fixed overflow issue on 32bit Raspberry Pi 2, Added DEBUG flags to Makefile

--------------------------------------------------------------------------------------
| CPU                                           | BogoMips| Comment   |Linux BogoMIPS|
|-----------------------------------------------|---------|-----------|--------------|
| ARMv7 Processor rev 5 (v7l) (Raspberry Pi 2)  | 149.05  | Pi 2      | 38.4         |
| Raspberry Pi 4 Model B Rev 1.2                | 189.66  | Pi 4      | 108          | 
| Intel(R) Atom(TM) CPU  330 @ 1.60GHz          | 318.29  | Plex      |3200          |
| 2.7 GHz Intel Core i5 (Macbook Pro Early 2015)| 420.71  | Laptop    |-             |
| Intel(R) Xeon(R) CPU E5-2673 v4 @ 2.30GHz     | 465.74  | Azure B2s |4590          |
| Intel(R) Pentium(R) CPU 4415U @ 2.30GHz       | 495.21  | Inspiron  |4608          |
| Intel(R) Pentium(R) CPU G3260 @ 3.30GHz       | 497.72  | Storage   |6598          |
| Intel(R) Core(TM) i7-9700K CPU @ 3.60GHz      | 823.42  | Monster   |7200          |
| Intel(R) Core(TM) i7-9700 CPU @ 3.00GHz       | 861.21  | Raptor    |6000          |