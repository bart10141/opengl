#define GL_SILENCE_DEPRECATION  // Silenciar advertencias sobre funciones obsoletas

#include <cstdio>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstring>

#include "math.h"

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
  Blanco,
  Negro,
  Gris
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
  void pintar_zona_de_pintado(float porcentaje_pantalla_util);
  void obtener_tam_ventana(GLFWwindow * window, int * ancho, int * alto);
  void rotar_poligono(float* x, float* y, int numVertices, float angulo);
  //void pintar_separaciones_ejes_cuadricula(GLFWwindow * window, int nseparaciones, float porcentaje_util_pantalla);
  void pintar_separaciones_ejes_cuadricula(GLFWwindow * window, float porcentaje_util_pantalla, float min,
                                           float max, int intervalo_separacion);
  float escalar(float valor, float min_real, float max_real, float min_nuevo_rango, float max_nuevo_rango);
};

