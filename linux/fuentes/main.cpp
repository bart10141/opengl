#include "renderizador_opengl.hpp"

#define ancho_ventana            800
#define alto_ventana             600
#define nombre_ventana           "Dentro de polígono"
#define porcentaje_util_pantalla 0.8f

int main() 
{

  GLFWwindow * window = nullptr; 
  manejador_opengl manejador(window, ancho_ventana, alto_ventana, nombre_ventana); 

  if (window == nullptr)
  {
    printf("Puntero nulo\n");
    return 0;
  }

  // manejador.ajustar_zona_pintado(window, porcentaje_util_pantalla);
  manejador.cambiar_color_limpiado_ventana(Color::Blanco);
  while (!manejador.ventana_cerrada(window)) 
  {
    manejador.limpiar_ventana();
    manejador.cambiar_color(Color::Negro);
    //manejador.pintar_recta_de_prueba();
    //manejador.pintar_poligono_de_prueba();
    //manejador.pintar_recta_de_prueba_zona_util();
    manejador.pintar_zona_de_pintado(0.8f);
    manejador.pintar_separaciones_ejes_cuadricula(window, 0.8f, 0, 7000, 1200);
    manejador.renderizar_pantalla(window);
    manejador.procesar_eventos_entrada();
  }
  manejador.cerrar_opengl(window);

  return 0;
}

