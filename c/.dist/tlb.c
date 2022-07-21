#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
const int PAGETABLE = 256;
const int BUFF = 256;
const int PHYSMEM = 128;
const int TLB = 16;
// ayush soni 202051043
//instead of making 1d array and 2d array i have taken a .bin file 
//where pre stored binary numbers are there as Store.bin
struct TLB {
	unsigned char TLBpage[16];
	unsigned char TLBframe[16];
	int ins;
};
	
int readFromDisk (int pageNo, char *op, int* QT){

	char buff[BUFF];
	memset(buff, 0, sizeof(buff));

	FILE *BS;
	BS = fopen("Store.bin", "rb");
	if (BS == NULL){
		printf("failed to open file\n");
		exit(0);
	}
	

	if (fseek(BS, pageNo * PHYSMEM, SEEK_SET)!=0)
		printf("errorfseek\n");

	if (fread(buff, sizeof(char), PHYSMEM, BS)==0)
		printf("errorfread\n");
	

	int i = 0;
	for(i; i < PHYSMEM; i++){
		*((op+(*QT)*PHYSMEM)+i) = buff[i];

	}
	
	(*QT)++;

	return (*QT)-1;


int findPage(int logicAddr, char* Pq, struct TLB *tlb,  char* op, int* QT, int* pageFault, int* TLBhit){

	unsigned char mask = 0xFF;
	unsigned char offset;
	unsigned char pageNum;
	bool TLBhits = false;
	int frame = 0;
	int value;
	int newFrame = 0;

	//printf("Virtual adress: %d\t", logicAddr);

	pageNum = (logicAddr >> 8) & mask;
	

	offset = logicAddr & mask;

	

	int i = 0;
	for (i; i < TLB; i++){
		if(tlb->TLBpage[i] == pageNum){
			frame = tlb->TLBframe[i];
			TLBhit = true;
			(*TLBhit)++;
		
		}
			
	}


	if (TLBhit == false){
		if (QT[pageNum] != -1){
		
		}

		
		else{

			newFrame = readFromDisk(pageNum, op, QT);
			QT[pageNum] = newFrame;
			(*pageFault)++;

		}
		frame = QT[pageNum];
		tlb->TLBpage[tlb->ins] = pageNum;
		tlb->TLBframe[tlb->ins] = QT[pageNum];
		tlb->ins = (tlb->ins + 1)%TLB;
		
	}
	int index = ((unsigned char)frame*PHYSMEM)+offset;
	value = *(op+index);
	//printf("Physical address: %d\t Value: %d\n",index, value);	
FILE *res = fopen("out.txt",	"a");
	fprintf(res,"Virtual address:%d is available at frame number:%d\n",	logicalAddr, frame);
	fclose(res);
	
	return 0;


}




int main (int argc, char* argv[]){
	
	int val;
	FILE *fd;
	int openFrame = 0;

	int pageFault = 0;
	int TLBhit = 0;
	int inputCount = 0;
	
	float pageFaultRate;
	float TLBHitRate;

	unsigned char PageTable[PAGETABLE];
	memset(PageTable, -1, sizeof(PageTable));	

	struct TLB tlb;	
	memset(tlb.TLBpage, -1, sizeof(tlb.TLBpage));
	memset(tlb.TLBframe, -1, sizeof(tlb.TLBframe));
	tlb.ins = 0;

	char PhyMem[PHYSMEM][PHYSMEM]; 

	if (argc < 2){
		printf("Not enough arguments\nProgram Exiting\n");
		exit(0);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL){
		printf("File failed to open\n");
		exit(0);
	}

	
	while (fscanf(fd, "%d", &val)==1){
	
		findPage(val, PageTable, &tlb, (char*)PhyMem, &openFrame, &pageFault, &TLBhit);
		inputCount++;
	}


	pageFaultRate = (float)pageFault / (float)inputCount;
	TLBHitRate = (float)TLBhit / (float)inputCount;
	printf("Page Fault Rate = %.4f\nTLB hit rate= %.4f\n",pageFaultRate, TLBHitRate);
	pclose(fd);
	return 0;
}
}