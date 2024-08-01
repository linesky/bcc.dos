#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
// need file libdos.c to be compile in directory
//bcc  -Md hello.c -o HELLO.COM
void cls3(cls1);
int main(argc,argv)
int argc;
char *argv[];
{
	int nn;
	int n;
	
	if(argc>0){
	        
	        n=1;
		nn=7*16+n;
	        cls3(nn);	
	}else{
		return 1;
	}
	
	return 0;
}
void cls3(cls1)
{
	int i;
	i=0xb800;
	movedata(__get_ds(),&i,__get_cs(),0x80,2);
	i=80*25*2-2;
	movedata(__get_ds(),&i,__get_cs(),0x82,2);
	i=(int)cls1;
	i=i<<8;
	i=i+32;
	movedata(__get_ds(),&i,__get_cs(),0x84,2);
	asm "push ds";
	asm "push cs";
	asm "pop ds";
	asm "mov bx,[0x82]";
	asm "mov cx,[0x84]";
	asm "mov ax,[0x80]";
	asm "push ax";
	asm "pop ds";
	asm "xor dx,dx";
	asm "dec dx";
	asm "dec dx";
	asm "mov ax,cx";

asm "label1:";
asm "mov [bx],ax";
asm "dec bx";
asm "dec bx";
asm "cmp bx,dx";
	asm "jnz label1";
	asm "pop ds";
	
	}
