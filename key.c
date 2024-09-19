
//bcc  -Md hello.c -o HELLO.COM

#define varn 0xc080



char getcc();
void sputs(cc);
void scopy(s1,s2);
void scat(s1,s2);
void slower(s1);
int main(argc,argv)
int argc;
char *argv[];
{
        char *r=" ";
        char *rr="\n";
        char *rrr;
	int nn;
	int n;
	cls3(0x2007);
	sputs("press a key\n");
	getcc();
	return 0;
}


char getcc(){
    char keys=getchar();
    sputc(keys);
    return keys;
}
void sputs(cc)
char *cc;
{
		int i=0;
while(cc[i]!=0){
		sputc(cc[i]);
		i++;
}
}
void scopy(s1,s2)
char *s1;
char *s2;
{
	char cc=0;
	int counter=0;
	do{
		s1[counter]=s2[counter];
		cc=s2[counter];
		counter++;
	}while(cc!=0);
	
}
void scat(s1,s2)
char *s1;
char *s2;
{
	char *s3;
	char cc=0;
	int counter=0;
	do{
		cc=s1[counter];
		counter++;
	}while(cc!=0);
	s3=s1+counter-1;
	scopy(s3,s2);
}

void slower(s1)
char *s1;
{
	char *s3;
	char cc=0;
	int counter=0;
	do{
		cc=s1[counter];
		if (cc>='A' && cc<='Z')s1[counter]=cc+32;
		counter++;
	}while(cc!=0);
}

#asm
.globl _cls3
.globl _sputc
.globl _getchar 
_cls3:
    mov si,sp
    add si,*0x2
    mov dx,[si]
    mov ax,*0xb800
    push ds
    mov ds,ax
    
    mov ax,dx
    mov cx,*0x8a0
    mov si,*0x1
    
cls31:
    
    mov [si],al    
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
_getchar:
    mov ax,*0
    int $16
    ret
#endasm

