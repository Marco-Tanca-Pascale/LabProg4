#ifndef TIPO_LIBRETA_H
#define TIPO_LIBRETA_H

// Agrego enum class asi no chocan los nombres de clases con valores de este enumerado
// Ahora para llamar un valor hay que utilizar TipoLibreta::X
enum class TipoLibreta {
    MotoProfesional,
    MotoAmateur,
    AutoProfesional,
    AutoAmateur
};

#endif
