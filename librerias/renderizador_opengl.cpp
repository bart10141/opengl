#include "renderizador_opengl.hpp"

manejador_opengl::manejador_opengl(GLFWwindow* &window ,int ancho_en_pixeles, int alto_en_pixeles, const char * nombre_ventana)
{
  if (ancho_en_pixeles < 0 || ancho_en_pixeles >= 1920)
  {
    ancho_en_pixeles = 1920;
  }

  if (alto_en_pixeles < 0 || alto_en_pixeles >= 1080)
  {
    alto_en_pixeles = 1080;
  }

  // Inicializar GLFW
  if (!glfwInit()) 
  {
    std::cerr << "Error al inicializar GLFW" << std::endl;      
  }

  // Crear una ventana con OpenGL
  window = glfwCreateWindow(ancho_en_pixeles, alto_en_pixeles, nombre_ventana, nullptr, nullptr);
  if (!window) 
  {
    std::cerr << "Error al crear la ventana" << std::endl;
    glfwTerminate();
  }

  // Hacer que el contexto OpenGL de la ventana actual sea el activo
  glfwMakeContextCurrent(window);
}

bool manejador_opengl::ventana_cerrada(GLFWwindow * window)
{
  return glfwWindowShouldClose(window);
}

void manejador_opengl::limpiar_ventana()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

// Pone al color indicado el fondo cuando se limpie la ventana.
void manejador_opengl::cambiar_color_limpiado_ventana(Color color)
{
  switch (color)
  {
    case Color::Blanco: 
      glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
      break;
    default:
      glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  }
}

void manejador_opengl::cambiar_color(Color color)
{
  switch (color) 
  {
    case Color::Rojo:
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case Color::Verde:
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case Color::Azul:
      glColor3f(1.0f, 0.0f, 0.0f);
      break;
    case Color::Blanco:
      glColor3f(0.0f, 0.0f, 0.0f);
      break;
  }
}

void manejador_opengl::pintar_recta(Puntos lista_de_puntos) 
{
  if (lista_de_puntos.npuntos != 2)
  {
    printf("Se ha excedido el número máximo de puntos para una recta\n");
    return;
  }

  glBegin(GL_LINES);
  for (int i = 0; i < lista_de_puntos.npuntos; i++) 
  {
    glVertex2f(lista_de_puntos.x[i], lista_de_puntos.y[i]);
  }
  glEnd();
}

void manejador_opengl::pintar_poligono(Puntos lista_de_puntos)
{
  if (lista_de_puntos.npuntos > MAX_PUNTOS)
  {
    printf("Número máximo de puntos de un polígono excedido.\n");
    return ;
  }

  glBegin(GL_POLYGON);
  for (int i = 0; i < lista_de_puntos.npuntos; i++)
  {
    glVertex2f(lista_de_puntos.x[i], lista_de_puntos.y[i]);
  }
  glEnd();
}

void manejador_opengl::renderizar_pantalla(GLFWwindow * window)
{
  // Intercambiar buffers (para renderizar lo que dibujamos)
  glfwSwapBuffers(window);

}

void manejador_opengl::procesar_eventos_entrada()
{
  // Procesar eventos de entrada
  glfwPollEvents();
}

void manejador_opengl::cerrar_opengl(GLFWwindow * window)
{
  // Limpiar recursos antes de salir
  glfwDestroyWindow(window);
  glfwTerminate();
}

void manejador_opengl::pintar_recta_de_prueba()
{
  Puntos lista_de_puntos;
  lista_de_puntos.x[0]    =  0.0f;
  lista_de_puntos.x[1]    =  0.0f;
  lista_de_puntos.y[0]    =  0.9;
  lista_de_puntos.y[1]    = -0.9f;
  lista_de_puntos.npuntos =  2;

  this -> pintar_recta(lista_de_puntos);
}

void manejador_opengl::pintar_poligono_de_prueba()
{
  Puntos lista_de_puntos;
  lista_de_puntos.x[0]    = -0.5f;
  lista_de_puntos.y[0]    =  0.0f;
  lista_de_puntos.x[1]    =  0.5f;
  lista_de_puntos.y[1]    =  0.0f;
  lista_de_puntos.x[2]    =  0.5f;
  lista_de_puntos.y[2]    =  0.5f;
  lista_de_puntos.npuntos =  3;


  this -> pintar_poligono(lista_de_puntos);
}

void manejador_opengl::ajustar_zona_pintado(GLFWwindow * window, float porcentaje_util)
{
  int ancho, alto;
  glfwGetWindowSize(window, &ancho, &alto);
  glViewport(ancho * ((1 - porcentaje_util)/2), alto * ((1 - porcentaje_util)/2), ancho * porcentaje_util, alto * porcentaje_util);
}

void manejador_opengl::pintar_recta_de_prueba_zona_util()
{
  Puntos lista_de_puntos;
  lista_de_puntos.x[0]    = -0.5f;
  lista_de_puntos.x[1]    =  0.0f;
  lista_de_puntos.y[0]    =  0.5f;
  lista_de_puntos.y[1]    =  0.0f;
  lista_de_puntos.npuntos =  2;

  this -> pintar_recta(lista_de_puntos);
}

void manejador_opengl::pintar_ejes()
{
  Puntos ejex;
  ejex.x[0]    = -0.9f;
  ejex.y[0]    = -0.9f;
  ejex.x[1]    =  0.9f;
  ejex.y[1]    = -0.9f;
  ejex.npuntos =  2;

  Puntos ejey;
  ejey.x[0]    = -0.9f;
  ejey.y[0]    = -0.9f;
  ejey.x[1]    = -0.9f;
  ejey.y[1]    =  0.9f;
  ejey.npuntos =  2;

  this -> pintar_recta(ejex);
  this -> pintar_recta(ejey);
}

void manejador_opengl::pintar_separaciones_ejes(GLFWwindow * window, float max, float min, int nseparaciones, float y_ejex, float x_ejey)
{
  Puntos recta;
  float  aux;
  float porcentaje_tam_linea = 0.02f;

  for (int i = 1; i <= nseparaciones; i++)
  {
    // Eje x
    aux = min + i * (max - min) / (nseparaciones + 1); 

    recta.x[0] = aux; 
    recta.y[0] = y_ejex + porcentaje_tam_linea;
    recta.x[1] = aux; 
    recta.y[1] = y_ejex - porcentaje_tam_linea;
    recta.npuntos = 2;
    this -> pintar_recta(recta);

    // Eje y
    recta.x[0] = x_ejey + porcentaje_tam_linea; 
    recta.y[0] = aux;
    recta.x[1] = x_ejey - porcentaje_tam_linea; 
    recta.y[1] = aux;
    recta.npuntos = 2;
    this -> pintar_recta(recta);
  }
}

void manejador_opengl::obtener_tam_ventana(GLFWwindow * window, int * ancho, int * alto)
{
  glfwGetWindowSize(window, ancho, alto);
}

void manejador_opengl::rotar_poligono(float* x, float* y, int numVertices, float angulo) {
    float cosTheta = cos(angulo);
    float sinTheta = sin(angulo);

    for (int i = 0; i < numVertices; ++i) {
        // Aplicar la matriz de rotación 2D a cada vértice
        float nuevoX = x[i] * cosTheta - y[i] * sinTheta;
        float nuevoY = x[i] * sinTheta + y[i] * cosTheta;

        x[i] = nuevoX;
        y[i] = nuevoY;
    }
}

// TO - DO
// Pintar triangulos y rotarlos para el final de los ejes.