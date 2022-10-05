#include<iostream>
#define MAX 100
using namespace std;

template<typename T,typename V >
class skiplist
{
private:
	class node{
		public:
		T data;
		V value;
		node* next=NULL;
		node* down=NULL;
		int level;

			node(T val,int level){
				this->data=val;
				this->level=level;
				this->next=NULL;
			}
	};
	node* start[MAX];
	int depth=0;
	int len=0;

	void start_(int length,T arr[],int level=0){
		this->start[level]=new node(arr[0],level);
		node* tmp=this->start[level];
		int i=1;
		while(i<length){
			node* now=new node(arr[i],level);
			tmp->next=now;
			tmp=now;
			i++;
		}
	}

	void create_up(int level){
		node* last=this->start[level-1];

		this->start[level]=new node(this->start[0]->data,level);
		node* tmp=this->start[level];
		tmp->down=last;
		if(last->next==NULL || last->next->next==NULL){
			return;
		}
		last=last->next->next;

		while(last!=NULL && last->next!=NULL){
			node* now=new node(last->data,level);
			now->down=last;
			tmp->next=now;
			tmp=now;
			last=last->next->next;
		}
	}
	int get_base(node* pos){
		node* tmp=pos;
		while(tmp->down!=NULL){
			tmp=tmp->down;
		}

		int i=0;
		node* ttmp=start[0];
		for(;;i++){
			if(ttmp==tmp){
				return i;
			}
			if(ttmp==NULL){
				return -1;
			}
			ttmp=ttmp->next;
		}

	}
	node* p(node* curr){
		node* tmp=curr;
		while(tmp->down!=NULL){
			tmp=tmp->down;
		}
		return tmp;
	}

	int search_(node** head,T val){
		node* tmp=*head;
		while(tmp!=NULL){
			cout<<tmp->data<<":"<<endl;
			if(tmp->data==val){
				return get_base(tmp);
			}
			if(tmp->next==NULL){
				cout<<"NULL";
				{
					if(tmp->down==NULL){
						return -2;
					}
					cout<<tmp->down->data;
					*head=tmp->down;
					return -1;
				}
			}
			if(tmp->data<val && tmp->next->data<=val){
				tmp=tmp->next;
				continue;
			}
			if(tmp->data<val && tmp->next->data>val){
				if(tmp->down==NULL){
					return -2;
				}else{
					*head=tmp->down;
					return -1;
				}
			}
		}
	}
	int search_by_level(node** head,T val,node** r){
		node* tmp=*head;
		while(tmp!=NULL){
			cout<<tmp->data<<":"<<endl;
			if(tmp->data==val){
				*r = p(tmp);
				return 0;
			}
			if(tmp->next==NULL){
				cout<<"ins NULL";
				{
					if(tmp->down==NULL){
						*r = tmp;
						return -2;
					}
					*head=tmp->down;
					*r=NULL;
					return -1;
				}
			}
			if(tmp->data<val && tmp->next->data<=val){
				tmp=tmp->next;
				continue;
			}
			if(tmp->data<val && tmp->next->data>val){
				if(tmp->down==NULL){
					*r=tmp;
					return -2;
				}else{
					*head=tmp->down;
					*r=NULL;
					return -1;
				}
			}
		}
	}
	node* get_pos(T val){
		node* begin=start[depth-1];
		node* aim=NULL;
		for(int i=0;aim==NULL;i++){
			search_by_level(&begin,val,&aim);
		}
		return aim;
	}
public:
	skiplist(){
		cout<<"0"<<endl;
	}
	skiplist(int len,T arr[]){
		this->len=len;
		cout<<"skiplist whith "<<len<<" element"<<endl;
		while((len>>=1)>0){
			this->depth++;
		}
		cout<<this->depth<<" level"<<endl;
		start_(this->len,arr);
		for(int i=1;i<(this->depth);i++){
			create_up(i);
		}

	}
	int search(T val){

		node* begin=start[depth-1];
		if(val<begin->data){
			return -1;
		}
		int flag=0;
		for(int i=0;i<depth;i++){
			cout<<"search "<<i<<endl;
			flag=search_(&begin,val);
			if(flag>=0){
				return flag;
			}else if(flag==-2){
				return -1;
			}
		}
	}
	int length(){
		return this->len;
	}
	int getlayers(){
		return this->depth;
	}
	int insert(T val){
		if(val<start[0]->data){
			node* tmp=start[0]->next;
			node* newnode=new node(start[0]->data,0);
			newnode->next = tmp;
			start[0]->next = newnode;
			for(int i =0;i<depth;i++){
				start[i]->data=val;
			}
			return 0;
		}
		node* pos=get_pos(val);
		node* tmp=pos->next;
		node* newnode=new node(val,0);
		newnode->next = tmp;
		pos->next = newnode;
		return 0;
	}

	void printLayer(int level){
		cout<<"values in level "<<level<<endl;
		node* tmp=this->start[level];
		while(tmp!=NULL){
			cout<<tmp->data<<"  ";
			tmp=tmp->next;
		}
		cout<<endl;
	}
};
int main(){
	int arr[10]={0,1,2,3,4,5,6,7,8,9};
	skiplist<int,int> *skip_list= new skiplist<int,int>(10,arr);
	skip_list->printLayer(0);
	skip_list->printLayer(1);
	skip_list->printLayer(2);
	skip_list->printLayer(3);

	for(int i=0;i<10;i++)
		cout<<"result i="<<skip_list->search(i)<<endl;

	skip_list->printLayer(0);
	skip_list->insert(-2);
	for(int i=2;i<15;i++)
		skip_list->insert(i);
	skip_list->printLayer(0);

	return 0;
}
