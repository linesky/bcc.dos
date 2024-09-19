
//bcc  -Md hello.c -o HELLO.COM
#define varn 0x0080

int main(argc,argv)
int argc;
char *argv[];
{
	int nn;
	int n;
	
	
	        
	        n=1;
		nn=0x0720;
	        cls3(nn);	
	
	
	return 0;
}
#asm
.globl _cls3
.globl _sputc 
_cls3:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ax,*0xb800
    push ds
    mov ds,ax
    
    mov ax,dx
    mov cx,*0x8a0
    mov si,*0x0
    
cls31:
    
    mov [si],ax   
    inc si
    inc si
    dec cx
    cmp cx,*0x0
    jnz cls31
    pop ds
    ret
_sputc:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ah,*02
    int *0x21
    ret

#endasm



