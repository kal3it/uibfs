#include "directorios/directorios.h"

void imprimirInodoInfo(unsigned int ninodo){
    inodo_t inodo;
    leer_inodo(ninodo,&inodo);

    printf("INFORMACION DEL INODO: \n");
    printf("Ninodo: %u\n",ninodo);
    printf("Tipo: %c\n",inodo.tipo);
    printf("Permisos: %u\n",inodo.permisos);
    printf("atime: %s\n",ctime(&inodo.atime));
    printf("mtime: %s\n",ctime(&inodo.mtime));
    printf("ctime: %s\n",ctime(&inodo.ctime));
    printf("nlinks: %u\n",inodo.nlinks);
    printf("tamEnBytesLog: %u\n",inodo.tamEnBytesLog);
    printf("numBloquesOcupados: %u\n",inodo.numBloquesOcupados);

    printf("punterosDirectos: %u\n",inodo.punterosDirectos[0]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[1]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[2]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[3]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[4]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[5]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[6]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[7]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[8]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[9]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[10]);
    printf("punterosDirectos: %u\n",inodo.punterosDirectos[11]);
    printf("punterosIndirectos0: %u\n",inodo.punterosIndirectos[0]);
    printf("punterosIndirectos1: %u\n",inodo.punterosIndirectos[1]);
    printf("punterosIndirectos2: %u\n",inodo.punterosIndirectos[2]);
    printf("\n");
}

int main(int argc, char const *argv[]){
    if (argc != 4) {
        puts("Uso: mi_creat <nombre_dispositivo> <pathname origen> <pathname destino>");
        return -1;
    }

    const char *camino1 = argv[2], *camino2 = argv[3];
    char *buffer;

    bmount(argv[1]);

//    mi_creat(camino1,7);

    if(mi_dir(camino1,buffer) < 0)      fprintf(stderr,"Erroraco\n");
    else                                fprintf(stderr,"%s\n",buffer);

//    if(mi_link(camino1, camino2) < 0)   fprintf(stderr,"Erroraco\n");
//    else                                fprintf(stderr,"Todo OK\n");

    //char str[26];
    //mi_write_f(ninodo,"Esto es kaleit.txt =0! :)",0,26);
    //mi_write_f(ninodo,"Esto es texto.txt =0! :)",0,25);
    //mi_read_f(ninodo,str,0,26);

    free(buffer);
    bumount();

    return 0;
}