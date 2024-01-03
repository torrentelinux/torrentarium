-- Base de datos Agenda para servidor PostgreSQL.
-- Ejecutar siendo admin. del sistema: psql -U postgres -f AgendaContactos.sql -w
-- La base de datos puede estar residiendo en un servidor local o remoto.
-- El servidor SQL puede estar corriendo en Windows o en Linux.

SET default_transaction_read_only = off;
SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET search_path = public, pg_catalog;
SET default_tablespace = '';
SET default_with_oids = false;
SET TIME ZONE 'America/Argentina/Tucuman';

CREATE DATABASE "agenda" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'es_AR.UTF-8' TABLESPACE = pg_default;
COMMENT ON DATABASE "agenda" IS 'Agenda personal de contactos.';
ALTER DATABASE "agenda" OWNER TO postgres;

\connect "agenda"
\conninfo

CREATE SEQUENCE contactos_codigo_seq INCREMENT 1 MINVALUE 1 MAXVALUE 2147483647 START 1 CACHE 1;

CREATE TABLE "public"."contactos" (
    "codigo" integer DEFAULT nextval('contactos_codigo_seq') NOT NULL,
    "nombre" character varying DEFAULT '<ponga aquí su nombre>' NOT NULL,
    "apellido" character varying DEFAULT '<ponga aquí su apellido>' NOT NULL,
    "alias" character varying DEFAULT '<ponga aquí su alias>' NOT NULL,
    "telefono" character varying DEFAULT '<ponga aquí su nº de teléfono>' NOT NULL,
    "correo-e" character varying DEFAULT '<ponga aquí su dir. correo electrónico>' NOT NULL,
    "Telegram-msj" character varying DEFAULT '<ponga aquí su dir. de Telegram>' NOT NULL,
    "X-msj" character varying DEFAULT '<ponga aquí su dir. de X>' NOT NULL,
    "sitio1" character varying(80) DEFAULT '<ponga aquí URL>' NOT NULL,
    "sitio2" character varying(80) DEFAULT '<ponga aquí URL>' NOT NULL,
    CONSTRAINT "contactos_pkey" PRIMARY KEY ("codigo")
) WITH (oids = false);

-- Comentarios en los campos de la tabla
COMMENT ON COLUMN "public"."contactos"."codigo" IS 'código del contacto.';
COMMENT ON COLUMN "public"."contactos"."nombre" IS 'nombres del contacto.';
COMMENT ON COLUMN "public"."contactos"."apellido" IS 'apellidos del contacto.';
COMMENT ON COLUMN "public"."contactos"."correo-e" IS 'correo electrónico del contacto.';
COMMENT ON COLUMN "public"."contactos"."sitio1" IS '1º sitio del contacto.';
COMMENT ON COLUMN "public"."contactos"."sitio2" IS '2º sitio del contacto.';
COMMENT ON COLUMN "public"."contactos"."alias" IS 'lista de alias del contacto.';
COMMENT ON COLUMN "public"."contactos"."telefono" IS 'nº de teléfono del contacto.';
COMMENT ON COLUMN "public"."contactos"."Telegram-msj" IS 'URL de mensajería Telegram.';
COMMENT ON COLUMN "public"."contactos"."X-msj" IS 'URL de mensajería X.';

-- Inserción de datos a la tabla
INSERT INTO contactos(codigo, nombre, apellido, alias, telefono, "correo-e", "Telegram-msj", "X-msj", sitio1, sitio2)
VALUES
     (1, 'usuario1', 'apellido1', 'alias1', 'telefono1', 'correo1', 'telegram1', 'xmsj1', 'sitio11', 'sitio21'),
     (2, 'usuario2', 'apellido2', 'alias2', 'telefono2', 'correo2', 'telegram2', 'xmsj2', 'sitio12', 'sitio22');

-- 13:35 sábado, 30 de diciembre de 2023
