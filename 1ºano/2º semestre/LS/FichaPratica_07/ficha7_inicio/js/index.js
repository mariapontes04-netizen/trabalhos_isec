function LinguagensScript() {
     return <h1>Linguagens Script!</h1>
}
// const LinguagensScript = () => <h1>Linguagens Script</h1>;
const LinguagensScript2 = ({nome}) => <h1 style={styleH1}>Bem Vindo {nome} à UC de Linguagens Script</h1>;
const LinguagensScript3 = (p) => <h1 style={styleH1}> Bem Vindo {p.nome} à UC de Linguagens Script</h1>;

const styleH1 = {
     fontFamily: 'sans-serif',
     textDecoration: 'underline',
     color: 'brown'
};

const containerRoot = document.getElementById("root");
const root = ReactDOM.createRoot(containerRoot);
root.render(
     <React.StrictMode>
          <LinguagensScript />
          <LinguagensScript />
          <LinguagensScript />
          <LinguagensScript />
          <LinguagensScript2 nome = "José Antunes" />
          <LinguagensScript3 nome = "Felipe Marques" />
          <InfoComponent title="React" src="react.png" url=" https://react.dev/"> React is a
               declarative, efficient, and flexible JavaScript library for building user interfaces. It lets you
               compose complex UIs from small and isolated pieces of code called "components". We use components
               to tell React what we want to see on the screen. When our data changes, React will efficiently
               update and re-render our components. A component takes in parameters, called props (short for
               “properties”), and returns a hierarchy of views to display via the render method.
          </InfoComponent>
          <InfoComponent title="Javascript" src="javascript.png"
               url="https://developer.mozilla.org/en-US/docs/Web/JavaScript">
               JavaScript (JS) is a lightweight, interpreted, or just-in-time compiled programming language with
               first-class functions. While it is most well-known as the scripting language for Web pages,
               many non-browser environments also use it, such as Node.js, Apache CouchDB and Adobe Acrobat.
               JavaScript is a prototype-based, multi-paradigm, single-threaded, dynamic language, supporting
               object-oriented, imperative, and declarative (e.g. functional programming) styles. Read more about
               JavaScript.
          </InfoComponent>
     </React.StrictMode >
);

function InfoComponent(props){
     return(
          <div className="wrapper">
               <div className="logo">
                    <img src={"images/" + props.src} alt={props.title}></img>
               </div>
               <div className="text">
                    <h2>{props.title}</h2>
                    <p>{props.children}</p>
                    <a href={props.url} target="_blank">Ler Mais</a>
               </div>
          </div>
     )
}
