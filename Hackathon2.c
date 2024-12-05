#include<stdio.h>
#include<stdlib.h> 
int main(){
	do{
		int check;
		int choice, n, temp, number, index, checkNumber, count3=0, count4=0;
		int count=0, count1=0,count2=0;
		int num[30];
		printf("\n******MENU******\n");
		printf("1. Nhap so phan tu va gia tri cho mang \n");
		printf("2. In ra cac phan tu trong mang theo dang num[0], num[1],.. \n");
		printf("3. Dem so luong cac phan tu chan le trong mang \n");
		printf("4. Tim gia tri lon thu 2 trong mang \n");
		printf("5. Them 1 phan tu vao dau mang \n");
		printf("6. Xoa 1 phan tu tai vi tri cu the \n");
		printf("7. Sap xep mang theo thu tu giam dan \n");
		printf("8. Nhap vao 1 phan tu va tim kiem phan tu do trong mang \n");
		printf("9. In ra toan bo so nguyen to trong mang duoc binh phuong \n");
		printf("10. Sap xep mang theo thu tu giam dan \n");
		printf("11. Thoat \n");
		printf("\t Lua chon cua ban la: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				 check = 1;
				printf("Moi nhap so phan tu cua mang: ");
				scanf("%d",&n);
				
				for(int i=0; i<n; i++){
					printf("Moi nhap cac phan tu vao mang: ");
					scanf("%d",&num[i]);
				}				
				break;
			case 2:
				if(check==1){
					printf("Cac phan tu co trong mang la: \n");
				for(int i=0; i<n; i++){
					printf("num[%d]=%d\n",i, num[i]);
				}
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 3:
				if(check==1){
					//Ddem so luong cac phan tu chan le;
				for(int i=0; i<n; i++){
					if(num[i]%2==0){
						count++;
					}else{
						count1++;
					}
				}
				printf("So cac so chan la: %d\n",count);
				printf("So cac so le la: %d\n", count1);
				
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 4:
				if(check==1){
					//Tim gia tri lon thu 2 trong mang
				for(int i=0; i<n; i++){
					for(int j=0; j<n-i-1; j++){
						if(num[j]>num[j+1]){
							temp=num[j];
							num[j] = num[j+1];
							num[j+1] = temp;
						}
					}
				}
				printf("\nPhan tu lon thu 2 trong mang la: %d",num[n-2]);
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 5:
				//Them 1 phan tu vao dau mang
				printf("\nMoi nhap vao so nguyen muon them ");
				scanf("%d",&number);
				for(int i = n+1; i>=0;i--){
					num[i] = num[i-1];		 
				}
				num[0] = number;
				for(int i = 0; i<n+1; i++){
					printf("%d\t",num[i]);
					}
				n++;
				break;
			case 6:
				if(check==1){
					//Xoa 1 phan tu tai vi tri cu the
				printf("Moi nhap vi tri muon xoa: ");
				scanf("%d",&index);
				for(int i=index-1; i<n-1; i++){
					num[i]=num[i+1];
				}
				printf("Mang sau khi xoa la: \n");
				for(int i=0; i<n-1; i++){
					printf("%d\t",num[i]);
				}
				n--;
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 7:
				if(check==1){
					//Sap xep mang theo thu tu giam dan
				for(int i=0; i<n; i++){
					int temp = num[i];
					int j = i-1;
					while(j>=0 && num[j] < temp){
						num[j+1] = num[j];
						j = j-1;
					}
					num[j+1] = temp;
				}
				printf("Mang sap xep theo giam dan: \n");
				for(int i=0; i<n; i++){
					printf("%d\t",num[i]);
				}
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 8:
				if(check==1){
					//Sap xep mang
				for(int i=0; i<n; i++){
					for(int j=0; j<n-i-1; j++){
						if(num[j]>num[j+1]){
							temp=num[j];
							num[j]=num[j+1];
							num[j+1]=temp;
						}
					}
				}
				//Nhap vao 1 phan tu va tim kiem phan tu do trong mang(Binary search)
				printf("Nhap vao phan tu muon tim: ");
				scanf("%d",&checkNumber);
					int start=0, end = n-1 , mid, flag=-1;
					while(start<=end){
						int mid = (start+end)/2;
						if(num[mid]>checkNumber){//chung to item phai nam ve ben trai, nho hon
							end = mid-1;
						}else if(num[mid]<checkNumber){//chung to item phai nam ve ben phai, lon hon
							start = mid + 1;
						}else{
							flag = mid; 
							printf("Phan tu %d co vi tri la %d ",checkNumber, mid+1);
							break; 
						}
					}
					if(flag==-1){
						printf("Khong co phan tu %d trong mang",checkNumber); 
					}		
				}else{
					printf("Mang chua co du lieu ");
				}
			
								
				break;
			case 9:
				if(check==1){
					//In ra so nguyen to
				for(int i=0; i<n; i++){
					count3=0;
					for(int j=2; j<=num[i]; j++){
						if(num[i]%j==0){
							count3++;
						}
					}
					if(count3==1){
						printf("\nSo nguyen to: %d --> %d",num[i], num[i]*num[i]);
						count4++;
					}
					
				}
				if(count4==0){
					printf("\nKhong co so nguyen to trong mang ");
				}
				}else{
					printf("Mang chua co du lieu ");
				}
				break;
			case 10:
				if(check==1){
					//Sap xep mang theo thu tu giam dan
				for(int i=0; i<n; i++){
					for(int j=0; j<n-i-1; j++){		
						if(num[j]<num[j+1]){
							temp=num[j];
							num[j] = num[j+1];
							num[j+1] = temp;
						}
					}
				}
				printf("Mang sau khi sap xep la: \n");
				for(int i=0; i<n; i++){
					printf("%d\t",num[i]);
					
				}
				}else{
					printf("Mang chua co du lieu ");
				}
				
				break;
			case 11:
				exit(0);
				break;
			default:
				printf("Default"); 
		}
		
	}while(1);
	return 0;
}
