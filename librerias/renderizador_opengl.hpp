#define GL_SILENCE_DEPRECATION  // Silenciar advertencias sobre funciones obsoletas

#include <cstdio>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstring>

#define MAX_PUNTOS 10

typedef struct {
  float x[MAX_PUNTOS];
  float y[MAX_PUNTOS];
  int   npuntos;
} Puntos;

enum class Color 
{
  Rojo,
  Verde,
  Azul,
  Blanco
};

class manejador_opengl
{
public:
  manejador_opengl(GLFWwindow* &window ,int ancho_en_pixeles, int alto_en_pixeles, const char * nombre_ventana);
  bool ventana_cerrada(GLFWwindow * window);
  void limpiar_ventana();
  void cambiar_color_limpiado_ventana(Color color);
  void cambiar_color(Color color);
  void pintar_recta(Puntos lista_de_puntos); 
  void pintar_poligono(Puntos lista_de_puntos);
  void renderizar_pantalla(GLFWwindow * window);
  void procesar_eventos_entrada();
  void cerrar_opengl(GLFWwindow * window);
  void pintar_recta_de_prueba();
  void pintar_poligono_de_prueba();
  void ajustar_zona_pintado(GLFWwindow * window, float porcentaje_util);
  void pintar_recta_de_prueba_zona_util();
  void pintar_ejes();
  void pintar_separaciones_ejes(GLFWwindow * window, float max, float min, int nseparaciones, float x_ejex, float y_ejey);
  void obtener_tam_ventana(GLFWwindow * window, int * ancho, int * alto);
};

