
//bcc  -Md hello.c -o HELLO.COM

#define varn 0xc080

void cls3(cls1);
void sputc(cc);
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
	cls3(0x71);
	nn=argc;
	if(argc>1){
		for (n=1;n<nn;n++){
		        rrr=argv[n];	
			sputs(rrr);
			sputs(r);
		}
		sputs(rr);
	}else{
		return 1;
	}
	return 0;
}
void cls3(cls1)
{
        int *c;
	c = (int * ) varn;
		*(c + 0)=cls1;
		
		asm	"db 0x1e,0x3e,0x8b,0x16,0x80,0xc0,0xbb,0x01,0x00,0xb8,0x00,0xb8,0xb9,0xd0,0x07,0x8e,0xd8,0x88,0xd0,0x3e,0x88,0x07,0x43,0x43,0x49,0x83,0xf9,0x00,0x75,0xf5,0x1f";
		
	

	
	}
void sputc(cc)
char cc;
{
	int *c;
	c = (int * ) varn;
	*(c + 0) = cc;

	asm	"db 0xbb,0x80,0xc0,0x8a,0x47,0x0,0xbb,0x7,0x0,0xb4,0x0e,0xcd,0x10";
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



