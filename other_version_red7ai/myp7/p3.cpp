#include "const.h"
#include "env.h"

Envirnment env;

int main(){
	Init();
//	freopen("p1.in","r",stdin);
//	freopen("p1.out","w",stdout);
	env.Read();
	env.Init();
//	env.Print_prb();
	env.Play();
//	env.Print();
//	env.Print_prb();
	cout<<clock()<<endl;
	return 0;
}
