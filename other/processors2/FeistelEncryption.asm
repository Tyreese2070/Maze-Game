Split plaintext P into to parts above RAM16 (L0 + R0)
Function on (R0) of plaintext with key
L0 XOR F(R0, KEY)
Loop with i
Function F(A,B) = A XOR NOT B

// KEY RAM1, PLAINTEXT RAM2, OUT RAM0

/L0 in RAM[17], R0 in RAM[18]
(SPLIT)
// ????

// XOR Between Ri and NOT Ki
// Output of function stored in RAM[19]
(FUNCTION)
@R1
D=!M
@R18
D=D-M
D=M
@FFALSE
D;JEQ
@19
M=1
@END
0;JMP

(FFALSE)
@R19
M=0

(FEND)
// -----------------------

// XOR Between Li and F(Ri, Ki)
(XOR)
@R19
D=M
@R4
D=D-M
D=M
@XORFALSE
D;JEQ
@R5
M=1
@XOREND
0;JMP
(XORFALSE)
@R5
M=0

(XOREND)
// ------------------


// Rotate the key for next iteration
// Number of times to rotate in R20
(ROTATE)
@R1
D=M
@R21
M=D

(MULTIPLY)
@R20
D=M
@REND
D;JLE
@R1
D=M
M=M+D
@R20
M=M-1
@MULTIPLY
0;JMP

(REND)
//------------------------