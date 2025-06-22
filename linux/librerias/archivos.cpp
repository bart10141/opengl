cArchivo(char * ruta_de_archivo)
{
  archivo = fopen(ruta_de_archivo);
  t_archivo_b = tamanio_archivo_bytes(archivo);
  if (t_archivo_b > MAX_TAM_ARCHIVO_BYTES)
  {
    t_archivo_b = MAX_TAM_ARCHIVO_BYTES;
    printf("El tamaño del archivo excede %d bytes que es el máximo permitido\n");
  }

}
void obtener_bufer(char * bufer)
{

}

void cArchivo::cargar_archivo_memoria(char * bufer)
{

}

int tamanio_archivo_bytes(FILE * archivo)
{

}
