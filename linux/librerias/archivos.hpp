#ifndef ARCHIVOS_HPP
#define ARCHIVOS_HPP

// 100 MB
#define MAX_TAM_ARCHIVO_BYTES 100000000  

class cArchivo()
{
public:
  cArchivo(char * ruta_archivo);
  void obtener_bufer(char * bufer);
  void cargar_archivo_memoria(char * bufer);
  int tamanio_archivo_bytes(FILE * archivo);
private:
  FILE * archivo;
  int t_archivo_b;
}

#endif
