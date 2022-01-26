#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])
{
			 
       int sockfd;
       struct sockaddr_in serv_addr;
       struct hostent *server;
       char buffer[4096],choice[4096];
       sockfd=socket(AF_INET,SOCK_STREAM,0);
       
       serv_addr.sin_family=AF_INET;
       serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
       serv_addr.sin_port=htons(SERV_TCP_PORT);
       printf("\nReady for sending...");
       connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
       do
       {
       printf("\nEnter the message to send:\ncreate\ndelete\ncat\nedit\ndecline");     
       printf("\nClient: ");
       fgets(buffer,4096,stdin);
       strcpy(choice,buffer);
       send(sockfd,buffer,4096,0);
       
       if(strncmp(buffer,"create",6)==0)
       {
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         //sockfd1=socket(AF_INET,SOCK_STREAM,0);
         send(sockfd,buffer,4096,0);
         
         
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         send(sockfd,buffer,4096,0);
         
         recv(sockfd,buffer,4096,0);
         printf("Serverecho:   %s",buffer);

         
         
       }
       
       else if(strncmp(buffer,"delete",6)==0)
       {
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         send(sockfd,buffer,4096,0);
         
         recv(sockfd,buffer,4096,0);
         printf("Serverecho:      %s",buffer);
       }
       
       else if(strncmp(buffer,"cat",3)==0)
       {
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         send(sockfd,buffer,4096,0);
         
         
         recv(sockfd,buffer,4096,0);
         if(buffer[0]=='*')
         {
            printf("%s",buffer);
         }
         else
         {
         printf("%s",buffer);
         while(1)
         {
            recv(sockfd,buffer,4096,0);
            if(buffer[0]=='*')
            {
              break;
            }
            printf("%s",buffer);
         }
         }
         
       }
       else if(strncmp(buffer,"edit",4)==0)
       {
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         send(sockfd,buffer,4096,0);
         
        // sockfd1=socket(AF_INET,SOCK_STREAM,0);
         recv(sockfd,buffer,4096,0);
         printf("Serverecho: %s",buffer);
         fgets(buffer,4096,stdin);
         send(sockfd,buffer,4096,0);
         
         recv(sockfd,buffer,4096,0);
         printf("Serverecho:   %s",buffer);

         
         
       }
       else if(strncmp(buffer,"decline",7)==0)
       {
       		recv(sockfd,buffer,4096,0);
       		printf("Serverecho: %s",buffer);
       }
       else
       {
          recv(sockfd,buffer,4096,0);
          printf("Serverecho:   %s",buffer);
       }
       
       }while(strncmp(choice,"decline",7)!=0);
       
         printf("\n");
         close(sockfd);
         
         return 0;
}
