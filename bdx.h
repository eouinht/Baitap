#ifndef __BDX_H__
#define __BDX_H__
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
const int xedap[]= {1,
                    2, 
                    3, 
                    5};
const int xemay[]= {3, 
                    5, 
                    8, 
                    13};

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
//Ham so sanh bien so hai xe
int compare(xe x, xe y);
//ham so sanh thoi gian mot xe va 1 chuoi
int compareIn(xe x, char y[]);
//ham so sanh bien so xe mot xe va 1 chuoi
int comparePl(xe x, char y[]);
//ham khoi tao 
void Init(queue &q);
//Ham tao mot node trong queue
node* CreatNode(xe x);
//ham them node vao cuoi (mac dinh)
void add(queue &q, node* newnode);
//ham nhap 1 xe vao bai
int input(queue &q,them_xe x);
//ham tra ve chi so theo thu tu vao cua xe (bat dau tu 0)
void chiso(queue q, char a[]);
//ham kiem tra hang doi rong
bool IsEmpty(queue q);
//ham nhap node vao trong queue
void in(queue &q,char tg[], char bs[]);
// Ham xoa mot node trong queue __ xoa xe co bien so <plate> khoi bai
int Remove(queue q, char plateToDelete[]);
//ham xuat danh sach xe trong queue ra man hinh(nhung khong xoa)
void list(queue q);
//ham dem so xe may trong bai
int cnt_moto(queue q);
//ham kiem tra xem la xe may hay xe dap
int phanloai(char bienso[]);
//ham tinh tien gui 1 xe
int bill(queue q, xe &xoa);
//ham tinh tien toan bo so xe
int billall(queue q);

#endif
