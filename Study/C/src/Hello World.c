#include <stdio.h>

int main(void) {
  printf("Hello World!\n");
  return 0;
}
/*
disasm (x86-64)
  push rbp
  push rdi
  sub rsp, 0e8h
  lea rbp, [rsp+20h]
  lea rcx, [__9CE99571_main@c]
  call __CheckForDebuggerJustMyCode
  lea rcx, [string "Hello World!\n"]
  call printf
  xor eax, eax
  lea rsp,[rbp+0C8h]  
  pop rdi  
  pop rbp  
  ret
*/
