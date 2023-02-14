/*
** EPITECH PROJECT, 2023
** B-PDG-300-BDX-3-1-PDGRUSH3-nils.martin
** File description:
** ModuleKernel
*/

#ifndef MODULEKERNEL_HPP_
#define MODULEKERNEL_HPP_

#include <map>
#include "../AModule.hpp"
#include <sys/utsname.h>
#include <stdio.h>

class ModuleKernel : public AModule {
    public:
        ModuleKernel();
        ~ModuleKernel() = default;
        class ErrorKernel : public std::exception {
            public:
                ErrorKernel(const std::string &m_what);
                ~ErrorKernel() = default;
                std::string getErrorName() const;
                const char *what() const noexcept;
            private:
                std::string name;
        };
        void refreshData() final;
        struct utsname getData() const;

  private:
    struct utsname uts;
};

#endif /* !MODULEKERNEL_HPP_ */
