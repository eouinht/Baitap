#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;


char* lenh[]= {"list",
               "find", 
               "in", 
               "out", 
               "cnt-moto",
               "bill", 
               "billall",
               "*",
               "***"};
char* thoigian[]= {"06:00:00", 
                   "18:00:00"};
const int xedap[]= {1, 2, 3, 5};
const int xemay[]= {3, 5, 8, 13};

struct xe{
    char time[50];
    char plate[50];
    int tien_gui_xe;
};

typedef struct xe them_xe;
struct node{
    xe data;
    node *next;
};

struct queue{
    node *front;
    node *rear;
};
//Ham so sanh bien so xe
int compare(xe x, xe y){
    // neu tra ve 0 thi 2 bien so xe giong nhau
    //neu tra ve >0 thi bien so xe x > bien so xe y
    //neu tra ve <0 thi bien so xe x < bien so xe y
    return strcmp(x.plate, y.plate);
}
//ham so sanh thoi gian
int compareIn(xe x, char y[]){
    return strcmp(x.time,y);
}
int comparePl(xe x, char y[]){
    return strcmp(x.plate, y);
}

//ham khoi tao 
void Init(queue &q){
    //gan front va rear ve NULL
    q.front = NULL;
    q.rear = NULL;
}

//Ham tao mot node trong queue
node* CreatNode(xe x){
    node *p;
    p = new node;
    //neu p = NULL thi khong du bo nho de cap phat
    if(p == NULL) return NULL;
    //gan data bang x
    p->data = x;
    //gan con tro next bang NULL;
    p->next = NULL;
    return p;
}
//ham them node vao cuoi (mac dinh)
void add(queue &q, node* newnode){
    //neu hang doi rong thi them node vao cuoi hang doi
    if(q.front == NULL){
        q.front = newnode;
        q.rear = newnode; 

    }
    else{
        //nguoc lai thi them node vao sau node cuoi cung, tao node cuoi cung moi
        q.rear-> next = newnode;
        q.rear = newnode;
    }

}
//ham nhap 1 xe vao bai
int input(queue &q,them_xe x){
    if(q.front == NULL){
            return 1;
        }
    for(node* p = q.front; p!= NULL; p = p-> next){
        
        int check = compare(p->data, x);
        if(check != 0){
            return 1; //thanh cong
        }
        else return 0; //xe dang trong bai
        
        
        cout << "*" << endl;
    }
}
void chiso(queue q, char a[]){
    int index = 1 ;
    int i = 0;
    for(node* p = q.front; p != NULL; p = p-> next,i++){
        
        int check = comparePl(p->data, a); 
        
        if(check == 0){
            index = 0;
            cout << i << endl;
            
        }
        
       
    }
    if(index == 1 ) cout << "-1" << endl ;
    
}


bool IsEmpty(queue q){
    if(q.front == NULL) return true;
    else return false;
}

//ham nhap node vao trong queue
void in(queue &q,char tg[], char bs[]){
    //duyet 1 lan
   //nhap phan tu vao bien 
        
        them_xe them;
     
 //       cout << "Nhap du lieu cho xe" << endl;
 //       cout << "Nhap thoi gian xe vao: " << endl; 
        cin.ignore();
        strcpy(them.time,tg );
 //       cout << "Nhap bien so xe va ma ve xe ( xxxx-xxx.xx ): " << endl;
        strcpy(them.plate,bs);
        int index = input(q,them); 
        if(index == 0){
            cout << index << endl << "xe da trong bai" << endl;
        }else{
            node* p;
            p = CreatNode(them);
     
        //them node p vao queue
            add(q,p);
            
            // cout << index << endl;
        
       
        }
       
            
       
            
        

}

// Ham xoa mot node trong queue __ xoa xe co bien so <plate> khoi bai
int Remove(queue q, char plateToDelete[]){
    node* prev = NULL;
    node* current = q.front;
    // duyet queue de tim node chua bien so xe can xoa
    while (current != NULL) {
        if (strcmp(current->data.plate, plateToDelete) == 0) {
            break; //Tim thay node can xoa
        }
        prev = current;
        current = current->next;
       
    }
    
    if (current == NULL) {
        cout << "0" << endl;
        return 0;
    }
    
    //xoa node
    if (prev == NULL) {
        //node can xoa la node dau tien
        q.front = current->next;
    } else {
        prev->next = current->next;
    }
    
    delete current;
    cout << "1"<< endl;
    return 1;
}


//ham xuat danh sach xe trong queue ra man hinh(nhung khong xoa)
void list(queue q){
    //duyet tu dau den cuoi hang doi
    int k = IsEmpty(q);
    if(k == 1) cout << "Danh sach rong!" << endl;
    for(node* p = q.front; p != NULL; p = p->next){
        //hien thi data cua cac node;
        
        
        cout << p->data.plate << endl;
    }
   
}
//ham dem so xe may trong bai
int cnt_moto(queue q){
    char prexd[] = "xxxx"; 
    int moto = 0;
    int flag = 0;
    for(node* p = q.front; p != NULL; p = p-> next){
        for(int i = 0; i <4; i++){
            if(p->data.plate[i] != prexd[i]){
                flag++;
            }
        }
        if(flag == 4) moto++;
    }
    return moto;
}
//ham kiem tra xem la xe may hay xe dap
int checkXe(queue q){
    char prexd[] = "xxxx"; 
    for(node* p = q.front; p != NULL; p = p-> next){
        for(int i = 0; i <4; i++){
            if(p->data.plate[i] == prexd[i]) return 0;
            
        }
    
    }
    return 1;
}
int phanloai(char bienso[]){
    char preB[]="xxxx";
    int count=0;
    for(int i = 0; i < 4 ; i++){
        if(bienso[i] == preB[i]){
            count ++;
            
        }
    }
    if(count == 4 ) return 0;
    return 1;
}
//ham tinh tien gui 1 xe
int bill(queue q, xe &xoa){
    int check = phanloai(xoa.plate);
    for(node* p = q.front; p != NULL; p = p-> next){
        if(comparePl(p->data, xoa.plate) == 0) {
            if( compareIn(p->data,thoigian[0]) > 0 && strcmp(xoa.time,thoigian[1]) < 0) {
                if(check == 1) return xemay[0];
                 else return xedap[0];
            }else if(compareIn(p->data,thoigian[1]) > 0 && strcmp(xoa.time,thoigian[1]) >= 0){
                if(check == 1) return xemay[1];
                else return xedap[1];
            }
            else if(compareIn(p->data,thoigian[1]) >= 0 && strcmp(xoa.time,thoigian[1]) < 0 && strcmp(xoa.time, thoigian[0]) > 0){
                if(check == 1) return xemay[2];
                else return xedap[2];
            }
            else if(compareIn(p->data,thoigian[0]) <= 0 && strcmp(xoa.time,thoigian[1]) < 0){
                if(check == 1) return xemay[2];
                else return xedap[2];
            }
            if( compareIn(p->data,thoigian[0]) <= 0 && strcmp(xoa.time,thoigian[1]) >= 0){
                if(check == 1) return xemay[3];
                else return xedap[3];
            }
        }      
        }
    return -1;

}
//ham tinh tien toan bo so xe
int billall(queue q){
    int sum = 0;
     for(node* p = q.front; p != NULL; p = p-> next){
        int sumi = bill(q, p->data);
        sum += sumi;
     }
    return sum;
}
int main(){
    
    node * newnode;
    xe x;
    queue q;
    Init(q);
    int numMoto;

    int tienxe;
    int tientong;
    /*
    int chon;
    while(1){

    cout << "Menu: Tac vu" << endl; //ok
    cout << "1. In ra danh sach xe trong bai, theo thu tu cua input" << endl; //ok
    cout << "2. Tim xe co bien so <plate> " << endl; //ok
    cout << "3. Cho xe co bien so <plate> vao bai" << endl; //ok
    cout << "4. Cho xe co bien so <plate> ra khoi bai" << endl; //ok
    cout << "5. Dem so xe may co trong bai" << endl; //ok
    cout << "6. Tinh tien gui xe cho xe co bien <plate>" << endl;
    cout << "7. Tinh tien gui xe thu duoc tu khi bat dau chay truong trinh" << endl;
    cout << "----------------Nhap lua chon------------------ " << endl; cin >> chon;
    switch (chon)
    {
    case(1):
        list(q);
        break;
    case(2):
        cout << "Nhap bien so va ma the gui xe can tim : xxxx-xxx.xx " << endl; cin >> cantim;
        chiso(q, cantim);
        break;
    case(3):
        in(q);
        break;
    case(4):
        cout << "Nhap bien so xe can xoa: xxxx-xxx.xx " << endl; cin >> plateToDelete;
        Remove(q, plateToDelete);
        list(q);
        break;
    case(5):
        numMoto = cnt_moto(q);
        cout << "So xe may co trong bai: " << numMoto << endl;
        break;
    case(6):
        cout << "Nhap bien so xe va ma the gui xe muon tinh tien: xxxx-xxx.xx " << endl; cin >> plateBill;
        tienxe = bill(q, plateBill);
        cout << "Tien gui xe: " << tienxe << endl;
        break;
    case(7): 
        tienxe = billall(q);
        cout << "Tien gui xe tu khi chay chuong trinh: " << tienxe;
        break;
    default:
        cout << "Nhap lua chon: tu '1' den '7' " << endl;
        break;
    }
    }

    */

    char time[50], plate[50] ;
    char testcase[10000];
    int index = -1;
    int index2 ;
    int index3 = -1;
    int ind = -1;
    xe xoa;
        while( cin >> testcase){
        if(strcmp(testcase, lenh[7]) == 0) index = 0;
        else if(strcmp(testcase, lenh[0]) == 0) index2 = 1; 
        else if(strcmp(testcase, lenh[1]) == 0) index2 = 2;  
        else if(strcmp(testcase, lenh[2]) == 0) index2 = 3;  
        else if(strcmp(testcase, lenh[3]) == 0) index2 = 4;  
        else if(strcmp(testcase, lenh[4]) == 0) index2 = 5;  
        else if(strcmp(testcase, lenh[5]) == 0) index2 = 6;  
        else if(strcmp(testcase, lenh[6]) == 0) index2 = 7;  
        else if(strcmp(testcase, lenh[8]) == 0) index = 2;
   
        switch(index){
            case(-1): 
                    strcpy(x.time, testcase); index = 1; 
                    break;
            case(1) :
                    strcpy(x.plate, testcase); 
                    in(q, x.time, x.plate);           
                    index = -1;
                    delete &x;  
                
            case(0):
                    switch (index2){
                    case(1):              
                        list(q); 
                    break;
                        case(2):
                        while(cin >> testcase){              
                        chiso(q, testcase);
                        break; 
                        }
                    break;
                    case(3): 
                        while (cin>> testcase)
                        {
                            if(index3 == -1){strcpy(x.time, testcase); index3 = 1; 
                            }else{
                            strcpy(x.plate, testcase); 
                            in(q, x.time, x.plate);           
                            index3 = -1;
                            delete &x;  
                            break;
                            }
                        }
                          
                        break;
                    case(4):
                    while(cin >> testcase){
                    if(ind == -1){strcpy(xoa.time, testcase);  ind = 1;
                    }else{
                        strcpy(xoa.plate, testcase); ind = -1;
                        Remove(q, xoa.plate);
                        delete &xoa;
                        break;
                    }
                    }            
                    break;
                    case(5):
                    numMoto = cnt_moto(q);
                    cout << numMoto << endl;
                    case(6):
                    while(cin >> testcase){
                    if(ind == -1){strcpy(xoa.time, testcase);  ind = 1;
                    }else{
                        strcpy(xoa.plate, testcase); ind = -1;
                        tienxe = bill(q,xoa);
                        cout <<tienxe << endl; 
                        delete &xoa;
                        break;
                    }           
                    }
                    break;
                    case(7):
                        tientong = billall(q);
                    break;  
                    }
            case(2): 
                break;
          }
        }

    return 0;
}