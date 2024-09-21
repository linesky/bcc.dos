
//bcc  -Md hello.c -o HELLO.COM

#define varn 0xc080
#define bufsize 5000
    char extends[180];
    

void deletess(a,b);
char getss(s,i);
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
	char sss[1];
	int f1;
	int f2;
	int t;
	cls3(0x2007);
	if(argc<2)return 0;
		
	
		
		
		

			
		        deletess(argv[1]);
		
			
		
		
		
	return 0;
	
}
void deletess(a,b)
char *a;
char b;
{
    int n=0;
    int nn=0;
    char *ff;
    char *fff;
    char f1[180];;
    ff=f1;
    
    for(n=0;n<0x30;n++)ff[n]=0x0;
    for(n=1;n<0x13;n++)ff[n]=0x20;
    ff[0]=0x0;
    
    for(n=0;n<9;n++){
         if(a[n]=='.'){
             n=n+1;
             for(nn=0;nn<3;nn++)ff[nn+9]=a[nn+n];
             n=20;
         }else{
             ff[n+1]=a[n];
         }
    }
   
    
    fff=ff+1;
    sputs(fff);
    fff=ff+9;
    sputc('.');
    sputs(fff);
    
    deletes(ff);
}
char getss(s,i)
char *s;
int i;
{   
    int nn=0;
    int n=0;
    for (n=0;n<i-1;n++){
        s[n]=getcc();
        nn=n;
        
        if(s[n]==13){
            
            n=i+1;
            
        }
    }
    nn=nn+1;
    sputc(13);
    sputc(10);
    s[nn]=0;
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
.globl _opens
.globl _creates
.globl _closes
.globl _reads
.globl _writes
.globl _createsdir
.globl _deletes
.globl _opensfcb
.globl _closesfcb
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
_opens:
    mov si,sp
    add si,*2
    mov dx,[si]
    add si,*2
    mov al,[si]
    mov ah,*0x3d
    int $21
    ret
_creates:
    mov si,sp
    add si,*2
    mov dx,[si]
    add si,*2
    mov cx,[si]
    mov ah,*0x3c
    int $21
    ret
_closes:
    mov si,sp
    add si,*2
    mov bx,[si]
    mov ah,*0x3e
    int $21
    ret
_reads:
    mov si,sp
    add si,*2
    mov bx,[si]
    add si,*2
    mov dx,[si]
    add si,*2
    mov cx,[si]
    mov ah,*0x3f
    int $21
    ret
_writes:
    mov si,sp
    add si,*2
    mov bx,[si]
    add si,*2
    mov dx,[si]
    add si,*2
    mov cx,[si]
    mov ah,*0x40
    int $21
    ret
_createsdir:
    mov si,sp
    add si,*2
    mov dx,[si]
    mov ah,*0x39
    int $21
    ret
_deletes:
    mov si,sp
    add si,*2
    mov dx,[si]
    mov ah,*0x13
    int $21
    ret
_opensfcb:
    mov si,sp
    add si,*2
    mov dx,[si]
    mov ah,*0x0f
    int $21
    ret
_closesfcb:
    mov si,sp
    add si,*2
    mov dx,[si]
    mov ah,*0x10
    int $21
    ret
#endasm

