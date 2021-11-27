# KiCad-Autosport-Connector-Generator-Crappy
It's a simple program which generates a basic footprint for all Autosport connectors (I think so) by providing it some basic values like:

-{file_in_name}.csv - the table with values: "{pin_number};{x_value};{y_value}". Make sure that the CSV file has no white spaces at the end of the file. Using a autosport datasheet, jpg to table converter and some excel magic should reward you with a right table in a appropriate format.

-{file_out_name}.kicad_mod; - will crate if doesn't exists

-shell (outer) radius - i recomend using plug's outer radius

-component's name

-drill size (diameter)

-via outer diameter

To use the generated file you have to import it to your project via a footprint manager.

#works well enough

<a download="autosport_generator.exe" href="AUTOSPORT_PG/Debug/AUTOSPORT_PG.exe">
    DOWNLOAD EXE
</a>
