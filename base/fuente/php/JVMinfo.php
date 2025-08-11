<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
    <head>
	<meta http-equiv="content-type" content="text/html; charset=UTF-8">
	<title>PHP/Java</title>
    </head>
    <body>
	<?php
	    # JVMinfo.php
	    # torrentelinux - Agosto de 2025.
	    # Aplicación para Windows.
	    # Esta aplicación es software libre.
	    
	    $salida = null;
	    $estado = null;

	    # Máquina virtual Java del sistema local.
	    # Modifique $JVM según corresponda a su sistema Windows local.
	    $JVM = '"'."c:\\Program Files\\Java\\zulu24\\bin\\java.exe".'"';
	    
	    print '<b>JVMinfo</b> '."<br/>";
	    exec($JVM.' --version', $salida, $estado);
	    print '<br/>';
	    
	    print '<b><u>Versión de Java instalado en el sistema local:</u></b>'.'<br/>';
	    for($i = 0; $i < count($salida); $i++)
		print_r($salida[$i].'<br/>');
	    
	    print '<br/><br/><b><u>Configuración de la máquina virtual</u></b><br/>';
	    exec($JVM.' -XshowSettings 2>&1', $salida, $estado);
	    for($i = 0; $i < count($salida); $i++)
		print_r($salida[$i].'<br/>');

	    flush();
	?>
	<br><br>
	<hr>
	<div align="center"><a href="http://localhost/">Inicio</a><br></div>
    </body>
</html>
