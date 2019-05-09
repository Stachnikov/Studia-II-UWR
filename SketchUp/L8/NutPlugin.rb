# Nut plugin
# Initialization

require 'sketchup.rb'
require 'extensions.rb'

module MikołajStachnik
module NutPlugin

MikołajStachnikExtension = SketchupExtension.new "NutPlugin", "NutPlugin/NutPlugin"
MikołajStachnikExtension.description = "Nut plugin"
MikołajStachnikExtension.version     = "1.0.0"
MikołajStachnikExtension.creator     = "MikołajStachnik"
MikołajStachnikExtension.copyright   = "2019"

Sketchup.register_extension MikołajStachnikExtension, true

end # module NutPlugin
end # module MikołajStachnik