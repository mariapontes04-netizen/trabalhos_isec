import React, { useState, useEffect } from "react";

function Timer({ win })
{
  const [seconds, setSeconds] = useState(0);

  useEffect(() => {
    if (win !== 1) return; // Continue the timer if win is 0

    const interval = setInterval(() => {
      setSeconds(prevSeconds => prevSeconds + 1);
    }, 1000);

    return () => clearInterval(interval);
  }, [win]);

  return <>{seconds}</>;
}

export default Timer;
