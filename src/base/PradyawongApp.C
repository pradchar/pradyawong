#include "PradyawongApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<PradyawongApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

PradyawongApp::PradyawongApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  PradyawongApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  PradyawongApp::associateSyntax(_syntax, _action_factory);
}

PradyawongApp::~PradyawongApp()
{
}

// External entry point for dynamic application loading
extern "C" void PradyawongApp__registerApps() { PradyawongApp::registerApps(); }
void
PradyawongApp::registerApps()
{
  registerApp(PradyawongApp);
}

// External entry point for dynamic object registration
extern "C" void PradyawongApp__registerObjects(Factory & factory) { PradyawongApp::registerObjects(factory); }
void
PradyawongApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void PradyawongApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { PradyawongApp::associateSyntax(syntax, action_factory); }
void
PradyawongApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
