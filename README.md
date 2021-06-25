# Reverse Shell and Botnet (C++ & Python)

## CREDIT: Chetan Nayak

## Description about explorer.cpp/.exe

- Explorer is a completely random name to mascarade, this is used to launch for the reverse shell which would be on a Windows based PC
- The way to complete the reverse shell, the attacker PC (for me it's an Ubuntu box) will launch `netcat -lvnp 8080` or whatever port you designate
**Wine is supported by this script in the case of pure Linux users**

### To compile this program in the case that you would want to make changes is per OS:

> Linux
`i686-w64-mingw32-g++ -std=c++11 *name*.cpp -o *name*.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc`

> Windows
`g++ -std=c++11 *name*.cpp -o *name*.exe -s -lws2_32 -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc`

## For the botnet Python script

- The Python script interacts with the C++ malware, you launch it with a specific port and the usage it given within the script then you launch your malware
- It works and was written with the intention of **Python3**, definitely keep that in mind when running it. 

## Troubleshooting
> If there are any issues, check out these set of blogs on malware development: https://niiconsulting.com/checkmate/author/chetan_nayak/page/2/
