#include<bits/stdc++.h>
using namespace std;

class Word
{
public:
	string en,phs;
	vector<pair<string,string> > V;
	void outcninaline(){
		for (int i=0;i<V.size();i++) cout<<V[i].first<<"."<<V[i].second<<";";cout<<endl;
		return;
	}
};

vector<Word> W;

bool operator < (Word A,Word B);
bool getyn();
int random(int l,int r);
void Init();
void Mainmenu();
void Outp();
void Help();
void Practice();
void Insert();
void OutFormat();

int main(){
	Init();
	Mainmenu();
	Outp();
	return 0;
}

bool operator < (Word A,Word B){
	return A.en<B.en;
}

bool getyn(){
	char ch=getchar();
	while ((ch!='y')&&(ch!='n')) ch=getchar();
	return ch=='y';
}

int random(int l,int r){
	double dou=1.0*rand()/RAND_MAX;
	return min(r,(int)(dou*(r-l+1)+l));
}

void Init(){
	cout<<"Initiation start."<<endl;
	srand(time(0));
	ifstream Input("rc.dat");
	int n;Word In;Input>>n;
	cout<<"count object:"<<n<<endl;
	for (int i=1;i<=n;i++){
		Input>>In.en;Input>>In.phs;
		int k;Input>>k;In.V.clear();
		while (k--){
			string s1,s2;Input>>s1>>s2;
			In.V.push_back(make_pair(s1,s2));
		}
		W.push_back(In);
	}
	Input.close();
	cout<<"down"<<endl;
	system("clear");
	return;
}

void Outp(){
	cout<<"writing data to disk."<<endl;
	ofstream Output("rc.dat");
	sort(W.begin(),W.end());
	Output<<W.size()<<endl;
	for (int i=0,sz=W.size();i<sz;i++){
		Output<<W[i].en<<" "<<W[i].phs<<endl;
		Output<<W[i].V.size()<<endl;
		for (int j=0,szz=W[i].V.size();j<szz;j++)
			Output<<W[i].V[j].first<<" "<<W[i].V[j].second<<endl;
	}
	Output.close();return;
}

void Mainmenu(){
	string statement="English Recitation Privacy Project \n written by SYCstudio \n version 0.1-beta";
	do{
		cout<<statement<<endl;
		cout<<"words total : "<<W.size()<<endl<<endl;
		string Input;cin>>Input;
		if (Input=="p") Practice();
		else if (Input=="i") Insert();
		else if (Input=="q") break;
		else if (Input=="h") Help();
		else if (Input=="l") OutFormat();
		else if (Input=="s") Outp();
		system("clear");
	}
	while (1);
	return;
}

void Help(){
	system("clear");
	cout<<"p - practice.\ni - insert a new word.\nl - output the wordlist.\ns - save to the disk\nq - exit."<<endl;
	getchar();getchar();return;
}

void Practice(){
	int tot;bool entocn,cntoen,phstoencn,phscntoen,chfrc;
	string Input;
	cout<<"confirm the practice times:";cin>>tot;
	cout<<"enable en-to-cn mode?";entocn=getyn();
	cout<<"enable cn-to-en mode?";cntoen=getyn();
	cout<<"enable phs-encn mode?";phstoencn=getyn();
	cout<<"enable phs-en mode?";phscntoen=getyn();
	//cout<<"enable characteristic-force mode?";chfrc=getyn();
	getchar();
	cout<<"press any key to start."<<endl;
	getchar();
	while (tot--){
		system("clear");
		cout<<"less : "<<tot+1<<endl;
		int opt=random(1,4),id=random(0,W.size()-1);
		if (opt==1){
			if (entocn==0){
				++tot;continue;
			}
			int id=random(0,W.size()-1);
			cout<<"en to cn mode."<<endl;
			cout<<W[id].en<<" ["<<W[id].phs<<"]"<<endl;
			cout<<"cn:";cin>>Input;
			cout<<endl<<"ans:";W[id].outcninaline();
		}
		else if (opt==2){
			if (cntoen==0){
				++tot;continue;
			}
			cout<<"cn to en mode."<<endl;
			W[id].outcninaline();
			cout<<"en:";cin>>Input;
			cout<<endl;
			if (Input==W[id].en) cout<<"accepted."<<endl;
			else cout<<"wrong answer."<<endl;
			cout<<"en:"<<W[id].en<<" ["<<W[id].phs<<"]"<<endl;
		}
		else if (opt==3){
			if (phstoencn==0){
				++tot;continue;
			}
			cout<<"phs to en and cn mode."<<endl;
			cout<<"["<<W[id].phs<<"]"<<endl;
			cout<<"en:";cin>>Input;
			cout<<"cn:";cin>>Input;
			cout<<W[id].en<<" ";W[id].outcninaline();
		}
		else if (opt==4){
			if (phscntoen==0){
				++tot;continue;
			}
			cout<<"phs to en mode."<<endl;
			cout<<"["<<W[id].phs<<"] ";W[id].outcninaline();
			cout<<"en:";cin>>Input;
			cout<<endl;
			if (Input==W[id].en) cout<<"accepted."<<endl;
			else cout<<"wrong answer."<<endl;
			cout<<"en:";cout<<W[id].en<<endl;
		}
		getchar();getchar();
	}
	return;
}

void Insert(){
	system("clear");
	Word I;int k;I.V.clear();
	cout<<"en:";cin>>I.en;
	cout<<"phs:";cin>>I.phs;
	cout<<"df chrtc:";cin>>k;
	while (k--){
		string s1,s2;cin>>s1>>s2;
		I.V.push_back(make_pair(s1,s2));
	}
	W.push_back(I);return;
}

void OutFormat(){
	system("clear");
	for (int i=0,sz=W.size();i<sz;i++){
		cout<<W[i].en<<" ["<<W[i].phs<<"] ";W[i].outcninaline();
	}
	getchar();getchar();return;
}
