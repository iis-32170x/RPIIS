import asyncio
from datetime import datetime

from pydantic import BaseModel
from pydantic_ai import Agent
from loguru import logger


class MedicalRecord(BaseModel):
    """
    Represents a medical record.
    """
    date: datetime
    symptoms: str
    drugs: str
    recommendations: str


class User(BaseModel):
    """
    Represents a user.
    """
    
    name: str
    medical_history: list[MedicalRecord]

    def add_medical_record(self, record: MedicalRecord) -> None:
        """
        Adds a medical record to the user's medical history.

        Parameters
        ----------
        record : MedicalRecord
        """

        self.medical_history.append(record)


class Doctor:
    """
    Represents a doctor.
    """

    def __init__(self):
        self.__ai_agent = Agent(
            "google-gla:gemini-1.5-flash",
            system_prompt=(
                "Ты - медицинский ассистент. Твоя задача отвечать очень кратко, "
                "в одно предложение, без лишних слов.\n"
                "Если тебе пишут симптомы и просят написать лекарства, то тебе нужно "
                "написать пару названий лекарств, которые могут помочь, через запятую.\n"
                "Если тебе пишут симптомы и просят написать рекомендации, то тебе нужно "
                "написать пару рекомендаций (максимум 1-2 предложения), которые могут помочь."
                "Если симптомов очень много или написан бред, пиши 'никакие лекарства не помогут, и вам осталось недолго.'"
            )
        )

    def _get_drugs(self, symptoms: str) -> str:
        drugs = self.__ai_agent.run_sync(
            f"Напиши лекарства. Симптомы: {symptoms}")
        return drugs.data

    def _get_recommendations(self, symptoms: str) -> str:
        recoms = self.__ai_agent.run_sync(
            f"Напиши рекомендации. Симптомы: {symptoms}")
        return recoms.data


    def consultation(self, symptoms: str) -> tuple[str, str]:
        """
        Consults the doctor with the given symptoms.

        Parameters
        ----------
        symptoms : str

        Returns
        -------
        tuple[str, str]
        """

        try:
            loop = asyncio.new_event_loop()
            asyncio.set_event_loop(loop)

            drugs = self._get_drugs(symptoms)
            recoms = self._get_recommendations(symptoms)

            return drugs, recoms
        except Exception as e:
            logger.error(f"Error: {e}")
