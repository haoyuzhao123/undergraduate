#include "const.h"
#include "env.h"

Envirnment env;

int main(){
	Init();
	freopen("p1.in","r",stdin);
//	freopen("p1.out","w",stdout);
	env.Read();
	env.Print(fout,flog);
	env.Play();
	//cout<<clock()<<endl;
	return 0;
}
