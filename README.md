# mini-compiler-in-c
A mini compiler project in C language for Compiler Design Lab, Dept. of CSE, NITK. Use these commands successively in the terminal. Use tc1,tc2,...tcx.c as the test case files.
```bash
lex scanner.l
yacc -d parser.y
cc y.tab.c -ll -ly
./a.out tcx.c
```

The report for the first phase of this project has been uploaded to this repository. The file is 'Project 1-Report.pdf'.
Check the wiki page for more information. The same can be found in 'Documentaion.docx'.
