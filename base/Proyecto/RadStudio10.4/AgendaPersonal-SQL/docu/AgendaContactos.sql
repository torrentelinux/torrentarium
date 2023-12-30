-- Base de datos Agenda para servidor PostgreSQL.

\connect "agenda";

CREATE SEQUENCE contactos_codigo_seq INCREMENT 1 MINVALUE 1 MAXVALUE 2147483647 START 3 CACHE 1;

CREATE TABLE "public"."contactos" (
    "codigo" integer DEFAULT nextval('contactos_codigo_seq') NOT NULL,
    "nombre" character varying DEFAULT '<ponga aquí su nombre>' NOT NULL,
    "apellido" character varying DEFAULT '<ponga aquí su apellido>' NOT NULL,
    "correo-e" character varying DEFAULT '<ponga aquí su dir. correo electrónico>' NOT NULL,
    "sitio1" character varying(80) DEFAULT '<ponga aquí URL>' NOT NULL,
    "sitio2" character varying(80) DEFAULT '<ponga aquí URL>' NOT NULL,
    "alias" character varying DEFAULT '<ponga aquí su alias>' NOT NULL,
    "telefono" character varying DEFAULT '<ponga aquí su nº de teléfono>' NOT NULL,
    "Telegram-msj" character varying DEFAULT '<ponga aquí su dir. de Telegram>' NOT NULL,
    "X-msj" character varying DEFAULT '<ponga aquí su dir. de X>' NOT NULL,
    CONSTRAINT "contactos_pkey" PRIMARY KEY ("codigo")
) WITH (oids = false);

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

-- 13:35 sábado, 30 de diciembre de 2023
