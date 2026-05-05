#include <stdio.h>
#include <mysql.h>


int main() {
    MYSQL conexao;
    mysql_init(&conexao); //retorna um endere�o de uma estrutura MYSQL ou NULL em caso de erro de aloca��o de mem�ria.
    
     // mysql_real_connect estabelece uma conex�o com um servidor MySQL  
    if ( mysql_real_connect(&conexao, "localhost", "root", "Gabibi89*", "alunodb", 3306, NULL, 0) )
    {
       printf("\n Conexao ao banco realizada com sucesso!\n");
  	   //mysql_query(&conexao,"INSERT INTO clientes(nome, numero_conta, saldo) values('Emerson', '1', '5000');");
  	   //mysql_query(&conexao,"UPDATE clientes SET saldo = 700 WHERE saldo = '350'");
       //mysql_query(&conexao,"DELETE FROM clientes WHERE nome = 'Andre'");
       //mysql_query(&conexao,"DELETE FROM clientes");
	  
	  
    }
    else
    {
        printf("Falha de conexao alunodb\n");
       
    }
    
    return 0;
}
