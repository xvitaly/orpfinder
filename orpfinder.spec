Name: orpfinder
Version: 0.2.0
Release: 1%{?dist}

License: MIT
Summary: Command-line tool to find orphaned packages
URL: https://github.com/xvitaly/%{name}
Source0: %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: pkgconfig(libsolv)
BuildRequires: pkgconfig(libsolvext)

BuildRequires: cmake
BuildRequires: gcc-c++
BuildRequires: ninja-build

%description
%{name} is a simple command line tool for finding packages that no one depends
on in repositories.

Such packages can be safely removed.

%prep
%autosetup -p1

%build
%cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Release
%cmake_build

%install
%cmake_install

%files
%doc README.md
%license LICENSE
%{_bindir}/%{name}

%changelog
* Sun Apr 23 2023 Vitaly Zaitsev <vitaly@easycoding.org> - 0.2.0-1
- Updated to version 0.2.0.
