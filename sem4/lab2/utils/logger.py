import sys
from loguru import logger

logger.remove()
logger.add(sys.stderr, format="<green>{time:YYYY-MM-DD HH:mm:ss.SSS}</green> | <level>{level: <8}</level> | {file}:{line} - <level>{message}</level>")
