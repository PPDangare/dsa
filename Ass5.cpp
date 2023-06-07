#include <iostream>
#include<string.h>
#define size 11
using namespace std;

class HashNode{
	string key_word;
	string val_meaning;
	HashNode *next;
public:
	HashNode(string word,string meaning){
		key_word=word;
		val_meaning=meaning;
		next=NULL;
	}
	friend class OpenHashing;
};

class OpenHashing{
	HashNode *ptr[size];
public:
	OpenHashing(){
		for(int i=0;i<size;i++){
			ptr[i]=NULL;
		}
	}

	int hashFun(string key){
		int sum=0;
		for(int i=0;i<key.length();i++){
			sum+=(int)key[i];
		}
		int hashcode=sum%size;
		return hashcode;
	}

	void insert(string word,string meaning){
		int hc=hashFun(word);
		HashNode *hn=new HashNode(word,meaning);
		if(ptr[hc]==NULL){
			ptr[hc]=hn;
		}
		else{
			HashNode *temp;
			temp=ptr[hc];
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=hn;
		}
	}

	void search(string key){
		int hc=hashFun(key);
		HashNode *temp=ptr[hc];
		while(temp!=NULL){
			if(temp->key_word==key){
				cout<<"Word Found!!"<<endl;
				return;
			}
			temp=temp->next;
		}
		cout<<"Word not Found!!"<<endl;
	}

	void Deletew(string key){
		int hc=hashFun(key);
		HashNode *prev=NULL;
		if(ptr[hc] == NULL){
		            cout<<"data not found"<<endl ;
		            return ;
		        }
		        if(ptr[hc]->key_word == key){
		            prev = ptr[hc] ;
		            ptr[hc] = prev->next ;
		            delete prev ;
		        }
		        else{
		HashNode *temp=ptr[hc];
		while(temp->next!=NULL){
			if(temp->next->key_word==key){
				break;
			}
			prev=temp->next;
			temp->next=temp->next->next;
		}
		if(prev!=NULL){
			prev->next=temp->next;
			delete temp;
		}
		else{
			cout<<"Not Found"<<endl;
		}
		        }
	}

	void update(string key, string new_meaning){
		int hc=hashFun(key);
		HashNode *temp=ptr[hc];
		while(temp!=NULL){
			if(temp->key_word==key){
				//flag=true;
				temp->val_meaning=new_meaning;
				return;
			}
			temp=temp->next;
		}
		cout<<"Not Found"<<endl;
	}

	void display(){
		for(int i=0;i<size;i++){
			if(ptr[i]!=NULL){
				cout<<i<<" ";
				HashNode *temp;
				temp=ptr[i];
				while(temp!=NULL){
					cout<<"("<<temp->key_word<<":"<<temp->val_meaning<<") -> ";
					temp=temp->next;
				}
				cout<<endl;
			}
			else{
				cout<<i<<" "<<endl;
			}
		}
	}
};

int main() {
	OpenHashing op;
	string word;
	string meaning;
	int ch;
	while(true){
		cout<<endl<<"Menu"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Update"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter word: ";
			cin>>word;
            cout<<"Enter the meaning: ";
            cin>>meaning;
            op.insert(word, meaning);
			break;
		case 2:
			cout<<"Enter word to be deleted: ";
			cin>>word;
            op.Deletew(word);
			break;
		case 3:
			cout<<"Enter word to be searched: ";
			cin>>word;
			op.search(word);
			break;
		case 4:
            cout<<"Enter word to be updated: ";
            cin>>word;
            cout<<"Enter the new meaning: ";
            cin>>meaning;
            op.update(word, meaning);
			break;
		case 5:
			op.display();
			break;
		case 6:
			return 0;
			break;
		default:
			cout<<"Enter valid choice!!"<<endl;
			break;
		}
	}

	return 0;
}

