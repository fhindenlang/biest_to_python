#include <vector>
#include <biest.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;


PYBIND11_MODULE(vacuum_field, m) {

    py::class_<sctl::Vector<double>>(m, "SCTLDoubleVector")
         .def(py::init<>())
         .def(py::init<const std::vector<double> & >());

    py::class_<sctl::Vector<int>>(m, "SCTLIntVector")
        .def(py::init<>())
        .def(py::init<const std::vector<int> & >());

    py::enum_<biest::SurfType>(m, "SurfType")
        .value("AxisymCircleWide", biest::SurfType::AxisymCircleWide)           // 125 x 50
        .value("AxisymCircleNarrow", biest::SurfType::AxisymCircleNarrow)       // 250 x 50
        .value("AxisymWide", biest::SurfType::AxisymWide)                       // 125 x 50
        .value("AxisymNarrow", biest::SurfType::AxisymNarrow)                   // 250 x 50
        .value("RotatingEllipseWide", biest::SurfType::RotatingEllipseWide)     // 125 x 50
        .value("RotatingEllipseNarrow", biest::SurfType::RotatingEllipseNarrow) // 250 x 50
        .value("Quas3", biest::SurfType::Quas3)                                 // 250 x 50
        .value("LHD", biest::SurfType::LHD)                                     // 250 x 50
        .value("W7X", biest::SurfType::W7X)                                     // 250 x 45
        .value("Stell", biest::SurfType::Stell)                                 // 250 x 50
        .value("W7X_", biest::SurfType::W7X_);

    py::class_<biest::ExtVacuumField<double>>(m, "vacuum_field")
        .def(py::init<>())
        .def("Setup", &biest::ExtVacuumField<double>::Setup)
        .def("ComputeBdotN", &biest::ExtVacuumField<double>::ComputeBdotN)
        .def("ComputeBplasma", &biest::ExtVacuumField<double>::ComputeBplasma);

    py::class_<biest::IntVacuumField<double>>(m, "int_vacuum_field")
        .def(py::init<>())
        .def("Setup", &biest::IntVacuumField<double>::Setup)
        .def("ComputeBdotN", &biest::IntVacuumField<double>::ComputeBdotN)
        .def("ComputeB", &biest::IntVacuumField<double>::ComputeB);
}
/**
    py::class_<VirtualCasing<double>>(m, "VirtualCasing")
        .def(py::init<>())
        .def("setup", &VirtualCasing<double>::Setup)
        .def("compute_external_B", &VirtualCasing<double>::ComputeBext)
        .def("compute_external_B_offsurf", &VirtualCasing<double>::ComputeBextOffSurf)
        .def("compute_external_gradB", &VirtualCasing<double>::ComputeGradBext);

    py::class_<VirtualCasingTestData<double>>(m, "VirtualCasingTestData")
        .def(py::init<>())
        .def_static("surface_coordinates", &VirtualCasingTestData<double>::SurfaceCoordinates)
        .def_static("magnetic_field_data", &VirtualCasingTestData<double>::BFieldData)
        .def_static("magnetic_field_grad_data", &VirtualCasingTestData<double>::GradBFieldData);

}
**/
