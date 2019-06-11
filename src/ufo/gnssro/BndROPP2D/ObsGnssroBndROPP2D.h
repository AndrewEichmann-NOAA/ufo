/*
 * (C) Copyright 2017-2018 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_GNSSRO_BNDROPP2D_OBSGNSSROBNDROPP2D_H_
#define UFO_GNSSRO_BNDROPP2D_OBSGNSSROBNDROPP2D_H_

#include <memory>
#include <ostream>
#include <string>

#include "oops/base/Variables.h"
#include "oops/util/ObjectCounter.h"
#include "ufo/gnssro/BndROPP2D/ObsGnssroBndROPP2D.interface.h"
#include "ufo/ObsOperatorBase.h"

namespace eckit {
  class Configuration;
}

namespace ioda {
  class ObsSpace;
  class ObsVector;
}

namespace ufo {
  class GeoVaLs;
  class Locations;

// -----------------------------------------------------------------------------

/// GnssroBndROPP2D observation operator
class ObsGnssroBndROPP2D : public ObsOperatorBase,
                        private util::ObjectCounter<ObsGnssroBndROPP2D> {
 public:
  static const std::string classname() {return "ufo::ObsGnssroBndROPP2D";}

  ObsGnssroBndROPP2D(const ioda::ObsSpace &, const eckit::Configuration &);
  virtual ~ObsGnssroBndROPP2D();

// Obs Operator
  void simulateObs(const GeoVaLs &, ioda::ObsVector &) const;

// Other
  const oops::Variables & variables() const {return *varin_;}

  Locations * locations(const util::DateTime &, const util::DateTime &) const;

  int & toFortran() {return keyOperGnssroBndROPP2D_;}
  const int & toFortran() const {return keyOperGnssroBndROPP2D_;}

 private:
  void print(std::ostream &) const;
  F90hop keyOperGnssroBndROPP2D_;
  const ioda::ObsSpace& odb_;
  std::unique_ptr<const oops::Variables> varin_;
};

// -----------------------------------------------------------------------------

}  // namespace ufo

#endif  // UFO_GNSSRO_BNDROPP2D_OBSGNSSROBNDROPP2D_H_
