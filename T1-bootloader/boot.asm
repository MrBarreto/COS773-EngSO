; boot.asm
[BITS 16]
[ORG 0x7C00]

start:
    ; Inicializa os registradores de segmento
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00       ; Define o ponteiro de pilha seguro abaixo do bootloader

    ; Carrega o setor 2 do disco (o Kernel em C) para o endereço 0x1000
    mov ax, 0x1000       ; Segmento de destino (0x1000:0x0000)
    mov es, ax
    xor bx, bx           ; Offset de destino = 0

    mov ah, 0x02         ; Função da BIOS: Ler setores do disco
    mov al, 1            ; Número de setores para ler
    mov ch, 0            ; Cilindro 0
    mov dh, 0            ; Cabeça 0
    mov cl, 2            ; Setor 2 (o setor seguinte ao bootloader)
    mov dl, 0x00         ; Drive de disquete (ou drive atual)
    int 0x13             ; Chama a interrupção de disco da BIOS

    jc erro_disco        ; Se falhar, entra em loop de erro

    ; Salta para o endereço onde o código em C foi carregado (0x1000:0000)
    jmp 0x1000:0x0000

erro_disco:
    jmp $                ; Trava o PC em caso de erro

; Preenchimento do setor de boot (512 bytes) e assinatura mágica
times 510-($-$$) db 0
dw 0xAA55
