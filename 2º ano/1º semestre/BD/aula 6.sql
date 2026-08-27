exec naluno(2023133420);

--Ex.3
select lj.nome,
    sum(co.quantidade) as "NUM_LIVROS_VENDIDOS",
    round(avg(co.preco_unitario),2) as "PRECO_MEDIO",
    count(distinct l.genero) as "GENEROS_DIFERENTES"
from lojas Lj, vendas V, livros L, autores A, contem Co
where lj.codigo_loja = v.codigo_loja
and v.codigo_venda = co.codigo_venda
and co.codigo_livro = l.codigo_livro
and l.codigo_autor = a.codigo_autor
and lower(a.morada) like '%coimbra'
group by lj.nome
having sum(co.quantidade) >= 10
order by lj.nome asc, "NUM_LIVROS_VENDIDOS" desc;
EXEC SQLCHECK('FFHLPAKCRARVIKH');

--Ex.4
select distinct floor(c.idade / 10) || 'X' as "FAIXA_ETARIA",
    sum(co.quantidade) as "NUM_LIVROS_VENDIDOS",
    count(distinct v.codigo_venda) as "NUM_VENDAS",
    count(distinct c.codigo_cliente) as "NUM_CLIENTES_DIFERENTES"
from vendas V, clientes C, contem Co
where v.codigo_cliente = c.codigo_cliente
and v.codigo_venda = co.codigo_venda
and lower(c.morada) like '%barreiro'
group by floor(c.idade/10) || 'X'
having count(distinct v.codigo_venda)>1
order by 1;
EXEC SQLCHECK('FFUCFCLDCNPLJOZ');

--Ex.5
select titulo, preco_tabela as "PRECO_MAIS_ALTO"
from livros
where preco_tabela = (
        select max(preco_tabela)
        from livros
        );
EXEC SQLCHECK('FFXWHGKEFMVTKDT');

--Ex.6
select titulo, preco_tabela as "Preco_mais_Baixo"
from livros
where genero like '%Drama'
and preco_tabela = (
        select min(preco_tabela)
        from livros
        where genero like '%Drama'
        );
EXEC SQLCHECK('FFEWHCUFZRBYLVR');

--Ex.7
select titulo, paginas as "Num_Paginas", preco_tabela as "Preco_mais_Baixo"
from livros
where genero like '%Drama'
and preco_tabela <= ALL (
        select preco_tabela
        from livros
        where genero like '%Drama'
        );
EXEC SQLCHECK('FFLSWHGGDVCEMGJ');

--Ex.8
select preco_tabela as "Menor Preco de tabela", titulo
from livros L
where genero like '%Drama'
and NOT EXISTS (
        select titulo
        from livros L1
        where L1.preco_tabela > L.preco_tabela
        and genero like '%Drama'
        );
EXEC SQLCHECK('FFTBENOHGPWUNEU');

--Ex.9
select l.titulo as "Livro Mais Barato"
from livros L,
    (SELECT MIN(preco_tabela) as PRECO_MINIMO
     from livros
     where genero like '%Drama') preco_min
where genero like '%Drama'
and l.preco_tabela = preco_min.PRECO_MINIMO;
EXEC SQLCHECK('FFEAUOMICXDPOWY');

--Ex.10
select distinct a.nome
from autores A, livros L,
    (select avg(paginas) * 2 as DOBRO_MEDIA_PAGINAS from livros) media
where a.codigo_autor = l.codigo_autor
and l.paginas > media.DOBRO_MEDIA_PAGINAS
order by a.nome;
EXEC SQLCHECK('FFBAQQLJTBMDPLP');

--Ex.11
select a.nome,
    To_Char(a.data_nascimento, 'YYYY-MM') as "ANO_MES",
    count(l.Codigo_Livro) as "NUM_LIVROS"
from autores A, livros l 
where a.Codigo_Autor = l.Codigo_Autor
group by a.codigo_autor, a.nome, a.data_nascimento
having count(l.codigo_livro) > (
        select avg(Livros_Por_Autor)
        from (
            select count(l2.Codigo_Livro) as Livros_Por_Autor
            from livros L2
            group by l2.Codigo_Autor
        ) Subquery
    )
order by a.nome;
EXEC SQLCHECK('FFZODKCKMLJWQDJ');

--Ex.12
select l.titulo, 
    a.codigo_autor, 
    l.preco_tabela as "PRECO", 
    round(m.preco_medio, 3) as "PRECO_MEDIO",
    round(l.preco_tabela - m.preco_medio, 3) as "DIFERENÇA"
from livros L 
join autores A on a.codigo_autor = l.codigo_autor
join (
        select l2.codigo_autor,
        avg(l2.preco_tabela) as "PRECO_MEDIO"
        from livros l2 
        where l2.genero like '%Informática'
        group by l2.codigo_autor
        ) m on m.codigo_autor = l.codigo_autor
where a.morada like '%Portalegre'
and l.genero like '%Informática'
order by a.codigo_autor, l.titulo;
EXEC SQLCHECK('FFQNPFRLLABFRGU');

--Ex.13
select l.genero, l.titulo, l.unidades_vendidas
from livros L
where l.unidades_vendidas = (
    select MAX(l2.unidades_vendidas)
    from livros L2
    where l2.genero = l.genero
)
order by l.genero;
EXEC SQLCHECK('FFOJNOQMRYYJSYA');
