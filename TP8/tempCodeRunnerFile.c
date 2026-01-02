
    int *espectadoresPorFuncion;
    Sala sala;
} Pelicula;

// ====== PROTOTIPOS DE FUNCIONES ======					
void cargarPeliculas(Pelicula *pelis, int cant);
void cargarEspectadores(Pelicula *pelis, int cant);
void mostrarPeliculas(Pelicula *pelis, int cant);
void listarPorGenero(Pelicula *pelis, int cant, char genero[]);
float calcularPromedioEspectadores(Pelicula p);