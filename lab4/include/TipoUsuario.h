#ifndef TIPO_USUARIO_H
#define TIPO_USUARIO_H

// Agrego enum class asi no chocan los nombres de clases con valores de este enumerado
// Ahora para llamar un valor hay que utilizar TipoUsuario::X
enum class TipoUsuario {
    Conductor,
    Pasajero
};

#endif
