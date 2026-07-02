# COS773-EngSO

## Primeiro Trabalho - BootLoader X86

Nesse primeiro trabalho, o objetivo primordial era escrever um bootloader que carregasse um pequeno programa em C que lê caracteres do teclado e escreve eles na tela. Para isso, foi necessário seguir as features configuradas na BIOS a partir de interrupções pré-definidas:

- INT 0x16: Salva o resultado da leitura do teclado no registrador AL;
- INT 0x13: Lê dados do HD, são utilizados os registradores ES e BX para segmento e offset, CL para o setor de disco, DL para o drive, CH para o cilindro e DH para o head;
- INT 0x10: Escreve o resultado na tela, utiliza os registradores AH para o teletype output, AL para o caractere a ser escrito, Bh para a página de vídeo e BL para a cor do texto.

O bootloader é carregado pela BIOS na memória no endereço 0x7C00 e é lido do boot sector, os primeiros 512 bytes de um dispositivo bootável.
