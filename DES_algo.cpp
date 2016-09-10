#include <bits/stdc++.h>
#define ll long long int 
#define usll unsigned long long int
using namespace std;



int PC1[] = {57, 49,  41, 33,  25,  17,  9,
			 1, 58,  50, 42,  34,  26, 18,
			 10,  2,  59, 51,  43,  35, 27,
			 19, 11,   3, 60,  52,  44, 36,
			 63, 55,  47, 39,  31,  23, 15,
			 7, 62,  54, 46,  38,  30, 22,
			 14,  6,  61, 53,  45,  37, 29,
			 21, 13,   5, 28,  20,  12,  4};
int PC2[] =    {14, 17, 11, 24,  1,  5,
				3, 28, 15,  6, 21, 10,
				23, 19, 12,  4, 26,  8,
				16,  7, 27, 20, 13,  2,
				41, 52, 31, 37, 47, 55,
				30, 40, 51, 45, 33, 48,
				44, 49, 39, 56, 34, 53,
				46, 42, 50, 36, 29, 32};



int IP[] ={58, 50, 42, 34, 26, 18, 10, 2,
			60, 52, 44, 36, 28, 20, 12, 4,
			62, 54, 46, 38, 30, 22, 14, 6,
			64, 56, 48, 40, 32, 24, 16, 8,
			57, 49, 41, 33, 25, 17,  9, 1,
			59, 51, 43, 35, 27, 19, 11, 3,
			61, 53, 45, 37, 29, 21, 13, 5,
			63, 55, 47, 39, 31, 23, 15, 7};



int ME[] =  {32,  1,  2,  3,  4,  5,
			 4,  5,  6,  7,  8,  9,
			 8,  9, 10, 11, 12, 13,
			12, 13, 14, 15, 16, 17,
			16, 17, 18, 19, 20, 21,
			20, 21, 22, 23, 24, 25,
			24, 25, 26, 27, 28, 29,
			28, 29, 30, 31, 32,  1};



int S[][64]={{14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
			0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
			4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
			15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
			{15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
			 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
			 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
			13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
			{10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
			13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
			13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
			 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
			{ 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
			13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
			10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
			 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
			{ 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
			14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
			 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
			11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
			{12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
			10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
			 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
			 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
			{ 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
			13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
			 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
			 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
			{13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
			 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
			 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
			 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}};
int P[] =    {16,  7, 20, 21,
			29, 12, 28, 17,
			1, 15, 23, 26,
			5, 18, 31, 10,
			2,  8, 24, 14,
			32, 27,  3,  9,
			19, 13, 30,  6,
			22, 11,  4, 25};


int IP_inverse[] =  {40,  8, 48, 16, 56, 24, 64, 32,
					39,  7, 47, 15, 55, 23, 63, 31,
					38,  6, 46, 14, 54, 22, 62, 30,
					37,  5, 45, 13, 53, 21, 61, 29,
					36,  4, 44, 12, 52, 20, 60, 28,
					35,  3, 43, 11, 51, 19, 59, 27,
					34,  2, 42, 10, 50, 18, 58, 26,
					33,  1, 41,  9, 49, 17, 57, 25};


int key_shift_sizes[] = {-1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

string ascII_to_bin(string key,int len)
{
	string bin[]={"0000","0001","0010","0011","0100","0101","0110","0111","1000",
				  "1001","1010","1011","1100","1101","1110","1111"};
	ll i;
	string bkey="";
	for(i=0;i<len;i++){
		bkey=bkey+bin[((int)(key[i]))/16];
		bkey=bkey+bin[((int)(key[i]))%16];
	}
	return bkey;
}
struct  key_set
{
	bool k[48];
	bool c[28],d[28];
};
key_set *key_sets=(key_set*)malloc(17*sizeof(key_set));
void generate_keys(string bkey){
	bool bin_key[56];
	int i,j;
	

	bool tk[56];
	for(i=0;i<56;i++){
		tk[i]=((int)(bkey[PC1[i]-1]))-48;
	}
	
	for(i=0;i<28;i++){
		key_sets[0].c[i]=tk[i];
	}
	
	for(i=28;i<56;i++){
		key_sets[0].d[i-28]=tk[i];
	}
	for(i=1;i<17;i++){
		for(j=0;j<28;j++){
			key_sets[i].c[(j+28-key_shift_sizes[i])%28]=key_sets[i-1].c[j];
			key_sets[i].d[(j+28-key_shift_sizes[i])%28]=key_sets[i-1].d[j];
		}
		for(j=0;j<28;j++){
			tk[j]=key_sets[i].c[j];
		}
		
		for(j=0;j<28;j++){
			tk[j+28]=key_sets[i].d[j];
		}
		for(j=0;j<48;j++){
			key_sets[i].k[j]=tk[PC2[j]-1];
		}
	}
}
struct block_set
{
	bool l[32],r[32];
};
void set_SBox(bool tmp_r[],bool tmp_s[],int i){
	int li=2*tmp_r[i*6]+tmp_r[i*6+5];
	int ri=8*tmp_r[i*6+1]+4*tmp_r[i*6+2]+2*tmp_r[i*6+3]+tmp_r[i*6+4];
	int ind=li*16+ri;//cout<<li<<"\t"<<ri<<endl;
	int val=S[i][ind];
	ind=(i+1)*4-1;
	while(ind>(i+1)*4-5){
		tmp_s[ind]=val%2;
		val/=2;
		ind--;
	}
}
bool *process_block(string bplain_txt,int block_no)
{
	bool msg_ip[64];
	int i,j;
	for (i = 0; i < 64; ++i)
	{
		msg_ip[i]=(int)(bplain_txt[block_no*64+IP[i]-1])-48;
	}
	block_set *block_sets=(block_set*)malloc(2*sizeof(block_set));
	for (i = 0; i < 32; ++i)
		block_sets[0].l[i]=msg_ip[i];

	for (i = 32; i < 64; ++i)
		block_sets[0].r[i-32]=msg_ip[i];

	int prev,next;
	bool tmp_r[48],tmp_s[32];
	for(i=1;i<17;i++){
		if(i%2==1){
			prev=0;
			next=1;
		}
		else{
			prev=1;
			next=0;
		}
		for(j=0;j<48;j++)
		{
			tmp_r[j]=block_sets[prev].r[ME[j]-1];
			tmp_r[j]^=key_sets[i].k[j];
			//cout<<tmp_r[j];
		}//cout<<endl;
		for(j=0;j<8;j++)
		{
			set_SBox(tmp_r,tmp_s,j);
		}
		for(j=0;j<32;j++){
			block_sets[next].r[j]=block_sets[prev].l[j]^tmp_s[P[j]-1];
			block_sets[next].l[j]=block_sets[prev].r[j];
		}
		/*cout<<"L"<<i<<"\t";
		for(j=0;j<32;j++)
			cout<<block_sets[next].l[j];
		cout<<endl<<"R"<<i<<"\t";
		for(j=0;j<32;j++)
			cout<<block_sets[next].r[j];*/
	}
	bool *res=(bool*)malloc(64);
	for(i=0;i<64;i++){
		if(IP_inverse[i]>32){
			res[i]=block_sets[0].l[IP_inverse[i]-32-1];
		}
		else
			res[i]=block_sets[0].r[IP_inverse[i]-1];
		//cout<<res[i];
	}
	return res;
}
char *bin_to_hex_and_ascII(bool *in,char *ascII_data){
	int i,j=0;
	char *hout=(char*)malloc(20);
	char h[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=0;i<8;i++){
		int val1,val2;
		val1=8*in[i*8]+4*in[i*8+1]+2*in[i*8+2]+in[i*8+3];
		val2=8*in[i*8+4]+4*in[i*8+5]+2*in[i*8+6]+in[i*8+7];
		hout[j++]=h[val1];
		hout[j++]=h[val2];
		ascII_data[i]=(char)(val1*16+val2);
	}
	hout[j]='\0';
	ascII_data[i]='\0';
	return hout;
}
int main()
{
	string key,bkey,plain_txt,bplain_txt;
	ll txt_size,key_size;
	ll i,j,k;
	printf("Key (in ASCII): ");
	cin>>key;

	printf("Plain Text (in ASCII): ");
	cin>>plain_txt;


	txt_size=plain_txt.length();
	key_size=key.length();
	if(key_size!=8)
	{
		cout<<"KEY SIZE should be 8"<<endl;
		return 0;
	}
	while(txt_size%8!=0)
	{
		plain_txt[txt_size++]='0';
	}

	bkey=ascII_to_bin(key,key_size);
	//bkey="0001001100110100010101110111100110011011101111001101111111110001";
	bplain_txt=ascII_to_bin(plain_txt,txt_size);
	//bplain_txt="0000000100100011010001010110011110001001101010111100110111101111";
	generate_keys(bkey);
	int no_of_blocks=txt_size/8;
	for(i=0;i<no_of_blocks;i++)
	{
		cout<<"Decrypted Data of Block "<<i+1<<" : "<<endl;
		bool *output=process_block(bplain_txt,i);
		cout<<"Binary Data : ";
		for(j=0;j<64;j++)
			cout<<output[j];
		cout<<endl;
		char *ascII_data=(char*)malloc(10);
		char *houtput=bin_to_hex_and_ascII(output,ascII_data);
		cout<<"Hexa Data : "<<houtput<<endl;
		cout<<"ASC-II Data  : "<<ascII_data<<endl<<endl;
	}
}
