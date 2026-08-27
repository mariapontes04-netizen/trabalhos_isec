exec naluno(2023133420);

--Ex.3
CREATE SEQUENCE exp_sequencia;
SELECT exp_sequencia.CURRVAL FROM dual;
SELECT exp_sequencia.NEXTVAL FROM dual;
SELECT exp_sequencia.NEXTVAL FROM dual;
SELECT exp_sequencia.NEXTVAL from dual;
SELECT exp_sequencia.CURRVAL FROM dual;
DROP SEQUENCE exp_sequencia;
EXEC SQLCHECK('FKGFNXWCTITWNME');

--Ex.4
CREATE TABLE EDITORAS_BACKUP as
select *
from editoras;
drop table EDITORAS_BACKUP;
EXEC SQLCHECK('FKNJNXHDQJLUSPV');

--Ex.5
ALTER TABLE EDITORAS_BACKUP
ADD CONSTRAINT pk_editoras_backup PRIMARY KEY (N_CONTRIBUINTE);
EXEC SQLCHECK('FKYEXNXEUROHELV');

--Ex.6
CREATE SEQUENCE seq_editback
start with 11
increment by 1
nomaxvalue
nocycle;
drop sequence seq_editback;
EXEC SQLCHECK('FKYDNPXFPBWPIRC');
  
--Ex.7
INSERT INTO editoras_backup (codigo_editora, nome, numero_contribuinte, morada, telefone, fax)
VALUES (seq_editback.NEXTVAL,
        'D.Quixote',
        '901111111',
        'Rua Cidade de Córdova, n.2 2610-038 Alfragide, Portugal',
        '707252252',
        '707252253');
EXEC SQLCHECK('FKIVZGPGIOZKVZL');

--Ex.8
INSERT INTO editoras_backup (codigo_editora, nome, numero_contribuinte, morada, telefone, fax)
VALUES (seq_editback.NEXTVAL,
        'Almedina',
        '901212121',
        'Rua Fernandes Tomás, n.º 76 a 80, 3000-167 Coimbra, Portugal',
        '239851903',
        '239851904');
EXEC SQLCHECK('FKAQCEVHKASRDLO');

--Ex.9
SELECT seq_editback.CURRVAL FROM dual;
SELECT seq_editback.NEXTVAL FROM dual;
SELECT seq_editback.CURRVAL FROM dual;
EXEC SQLCHECK('FKNNXQTIRKBLACD');

--Ex.10
DROP SEQUENCE seq_editback;
EXEC SQLCHECK('FKEPPMCJBROFZHT');

--Ex.11
CREATE TABLE LIVROS_BACKUP AS
SELECT *
FROM LIVROS;
EXEC SQLCHECK('FKZBSHOOZEWQOTY');

--Ex.12
CREATE VIEW LIVROS_INFORMATICA AS
SELECT *
FROM LIVROS_BACKUP
WHERE Genero = 'Informática';
EXEC SQLCHECK('FKNAOLLKSLABNKG');

--Ex.13
INSERT INTO livros_informatica (codigo_livro, titulo,isbn, genero) VALUES (500,'Uma noite de Verão', 8000000001,'Informática');
INSERT INTO livros_informatica (codigo_livro, titulo,isbn, genero) VALUES (501,'O céu é azul',8000000002,'Romance');
INSERT INTO livros_backup (codigo_livro, codigo_editora, codigo_autor,titulo,isbn, genero) VALUES  (502,2, 2,'Longe de tudo',8000000003,'Informática');
EXEC SQLCHECK('FKPWADILYCFLUJD');

--Ex.14
DELETE FROM LIVROS_BACKUP;
EXEC SQLCHECK('FKAQXPRMLGWNPXE');

--Ex.15
DROP VIEW LIVROS_INFORMATICA;
EXEC SQLCHECK('FKJZDYONFMBBLTS');

--Ex.16
CREATE VIEW AUTOR_LIVRO as
select upper(a.nome) as Nome_Autor,
        upper(l.titulo) as Titulo_Livro
from autores A, LIVROS_BACKUP L 
where a.codigo_autor = l.codigo_autor;
EXEC SQLCHECK('FKUAXXVPLXQVHWW');
    
--Ex.17
SELECT * FROM AUTOR_LIVRO;
EXEC SQLCHECK('FKUZJQEQHXZGJJH');

--Ex.18
DELETE FROM LIVROS_BACKUP;
EXEC SQLCHECK('FKDGLKJRGRCADEV');

--Ex.19
SELECT * FROM AUTOR_LIVRO;
EXEC SQLCHECK('FKBMGXFSRZOUQYF');

--Ex.20
DROP TABLE LIVROS_BACKUP;
EXEC SQLCHECK('FKASZYETZHOLOEE');

--Ex.21
SELECT * FROM AUTOR_LIVRO;
EXEC SQLCHECK('FKGRFMEUNATDSFN');

--Ex.22
CREATE VIEW LIVROS_VENDIDOS AS
SELECT 
    lj.Nome AS NOME_LOJA,
    lb.Titulo AS TITULO_LIVRO,
    a.Nome AS NOME_AUTOR,
    SUM(c.Quantidade) AS QUANTIDADE_VENDIDA
FROM VENDAS v
INNER JOIN contem c ON v.codigo_venda = c.codigo_venda
INNER JOIN LIVROS lb ON c.codigo_livro = lb.codigo_livro
INNER JOIN AUTORES a ON lb.codigo_autor = a.codigo_autor
INNER JOIN LOJAS lj ON v.codigo_loja = lj.codigo_loja
GROUP BY lj.Nome, lb.Titulo, a.Nome
ORDER BY QUANTIDADE_VENDIDA DESC, lb.Titulo, lj.Nome;
EXEC SQLCHECK('FKNWSKQVNMPQGVI');

--Ex.23
SELECT table_name
FROM user_tables
ORDER BY table_name;
EXEC SQLCHECK('FKTDWYWWPTIMSOZ');

--Ex.24
SELECT constraint_name,
        constraint_type,
        status
FROM user_constraints
WHERE table_name = 'CONTEM';
EXEC SQLCHECK('FKFEPNHXETKIOZG');
