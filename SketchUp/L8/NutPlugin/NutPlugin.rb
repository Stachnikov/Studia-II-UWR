require 'sketchup.rb'

module MikołajStachnik
module NutPlugin

def NutPlugin.createNut(r,posx=0,posy=0,posz=0)
  model = Sketchup.active_model # Open model
  entities = model.entities # All entities in model
  selection = model.selection # Current selection

  centerdown = [0, 0, 0]
  centerup = [0,0,0 + 0.45 * r]
  nut = entities.add_circle(centerdown, Z_AXIS, r,6)
  nut_face = entities.add_face(nut)
  nut_face.pushpull(-(0 + 0.45 * r))
  upcircle = entities.add_circle(centerup, Z_AXIS, 0.866 * r,72)
  downcircle = entities.add_circle(centerdown, Z_AXIS, 0.866 * r,72)
  trUP = Geom::Transformation.translation [0, 0, 0.1 * r]
  trDOWN = Geom::Transformation.translation [0, 0, -0.1 * r]
  entities.transform_entities trUP, upcircle
  entities.transform_entities trDOWN, downcircle
  hole = entities.add_circle([0,0,(0 + 0.45 * r) + 0.1 * r], Z_AXIS, 0.6*r,72)

  hole[0].faces[0].pushpull -((0 + 0.45 * r) + 2*0.1 * r)
  nut_group = entities.add_group hole[0].faces[1].all_connected
  nut_group.transform! [posx, posy, posz]


  model.commit_operation
end


def NutPlugin.InitMenus
  menu = UI.menu('Plugins')

      menu.add_item('Create Nut'){
        prompts  = ["Radius","Pos X","Pos Y", "Pos Z"]
        defaults = [1.m, 0.m, 0.m, 0.m]
        list     = [""]
        input = UI.inputbox(prompts, defaults, list, "Nut settings")
        
        r = input[0]
        posX = input[1]
        posY = input[2]
        posZ = input[3]

        self.createNut(r,posX,posY,posZ)
	}
end

def NutPlugin.InitToolbar(path)
  ic1  = File.join(path,"icons/icon1.png")
  ic1b = File.join(path,"icons/icon1b.png")  

  toolb = UI::Toolbar.new("Nut plugin")

  tbutton1 = UI::Command.new("create Nut"){ 
  
	prompts  = ["Radius","Pos X","Pos Y", "Pos Z"]
    defaults = [1.m, 0.m, 0.m, 0.m]
    list     = [""]
    input = UI.inputbox(prompts, defaults, list, "Nut settings")
        
    r = input[0]
    posX = input[1]
    posY = input[2]
    posZ = input[3]

    self.createNut(r,posX,posY,posZ)
	}
  tbutton1.tooltip = tbutton1.status_bar_text = "Create a nut"
  tbutton1.small_icon = ic1
  tbutton1.large_icon = ic1b
  toolb.add_item(tbutton1)
  toolb.show    
end

NutPlugin.InitToolbar(Sketchup.find_support_file("Plugins/NutPlugin"))
NutPlugin.InitMenus

end # module NutPlugin
end # module MikołajStachnik