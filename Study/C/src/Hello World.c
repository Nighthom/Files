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
  lea rcx, [__9CE99571_main@c (07FF7C40F1008h)]
  call __CheckForDebuggerJustMyCode (07FF7C40E135Ch)
  lea rcx, [string "Hello World!\n" (07FF7C40E9C28h)]
  call printf (07FF7C40E118Bh)
  xor eax, eax
  lea rsp,[rbp+0C8h]  
  pop rdi  
  pop rbp  
  ret
*/
