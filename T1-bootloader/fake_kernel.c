char ler_teclado(void);
void printar_tela(char c);

void main() {
    
    while(1) {
        
	printar_tela('D');
	printar_tela('I');
	printar_tela('G');
	printar_tela('I');
	printar_tela('T');
	printar_tela('E');
	printar_tela('\n');

	char tecla = ler_teclado();
        

        if (tecla == '\r') {
            printar_tela('\r');
            printar_tela('\n');
        } else {
            printar_tela(tecla);
	    printar_tela('\n');
        }
    }
}

// Essa função faz uso da interrupção 0x16 para capturar um caractere do teclado e salvar no registrador AL, sendo passado em seguida para a variável caractere
char ler_teclado() {
    char caractere;
    __asm__ __volatile__(
        "mov $0x00, %%ah\n\t"  
        "int $0x16\n\t"        
        "mov %%al, %0\n\t"     
        : "=r"(caractere)
        :
        : "ah", "al"
    );
    return caractere;
}

// Função para mostrar um caractere na tela usando a INT 0x10, AH=0x0E (Teletype) e movendo de volta o carctere para AL para ser printado
void printar_tela(char c) {
    __asm__ __volatile__(
        "mov $0x0E, %%ah\n\t"  
        "mov %0, %%al\n\t"     
        "mov $0x00, %%bh\n\t"  
        "mov $0x07, %%bl\n\t"  
        "int $0x10\n\t"        
        :
        : "r"(c)
        : "ah", "al", "bh", "bl"
    );
}


