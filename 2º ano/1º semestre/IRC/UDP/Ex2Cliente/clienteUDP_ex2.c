/*=========================== Cliente basico UDP ===============================
Este cliente destina-se a enviar mensagens passadas na linha de comando, sob
a forma de um argumento, para um servidor especifico cuja locacao e' dada
pelas seguintes constantes: SERV_HOST_ADDR (endereco IP) e SERV_UDP_PORT (porto)

O protocolo usado e' o UDP.
==============================================================================*/


/*=========================== Cliente basico UDP ===============================
  Ex2: Aguarda resposta do servidor e mostra-a.
  Ex3: Mostra o porto local atribu√do ao socket UDP.
==============================================================================*/

#include <winsock.h>  
#include <stdio.h>  

#pragma comment (lib, "Ws2_32.lib")  

#define SERV_HOST_ADDR "127.0.0.1"  
#define SERV_UDP_PORT  6000  

#define BUFFERSIZE     4096  

void Abort(char* msg);

int main(int argc, char* argv[])
{
    SOCKET sockfd;
    int msg_len, iResult, nbytes;
    struct sockaddr_in serv_addr, local_addr;   //  local_addr exer3
    int local_len;
    char buffer[BUFFERSIZE];
    WSADATA wsaData;

    if (argc != 2) {
        fprintf(stderr, "Sintaxe: %s frase_a_enviar\n", argv[0]);
        (void)getchar();
        exit(EXIT_FAILURE);
    }

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        (void)getchar();
        exit(1);
    }

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET)
        Abort("Impossibilidade de criar socket");

    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
    serv_addr.sin_port = htons(SERV_UDP_PORT);

    msg_len = strlen(argv[1]);

    if (sendto(sockfd, argv[1], msg_len + 1, 0,
        (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR)
        Abort("O subsistema de comunicacao nao conseguiu aceitar o datagrama");

    printf("<CLI1>Mensagem enviada ... a entrega nao e' confirmada.\n");


    local_len = sizeof(local_addr);
    if (getsockname(sockfd, (struct sockaddr*)&local_addr, &local_len) == 0) {
        printf("<CLI1>Porto local atribuido: %d\n", ntohs(local_addr.sin_port));
    }

    //  aguardar resposta do servidor
    nbytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (nbytes == SOCKET_ERROR)
        Abort("Erro  da resposta do servidor");
    printf("<CLI1>Resposta recebida do servidor: %s\n", buffer);

    closesocket(sockfd);
    WSACleanup();

    printf("\n");
    (void)getchar();
    exit(EXIT_SUCCESS);
}

void Abort(char* msg)
{
    fprintf(stderr, "<CLI1>Erro fatal: <%s> (%d)\n", msg, WSAGetLastError());
    exit(EXIT_FAILURE);
}